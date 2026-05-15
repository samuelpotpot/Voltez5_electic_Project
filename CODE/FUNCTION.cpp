#include <iostream>
#include <fstream>
#include <iomanip>
#include "Main.h"
#include "database.h"

using namespace std;

void inputData(string appliances[], double watts[],
    double hours[], int& count)
{
    cout << "\n===== INPUT APPLIANCE DATA =====\n";

    cout << "How many appliances do you want to enter? ";
    cin >> count;

    while (count <= 0 || count > MAX)
    {
        cout << "Invalid number. Enter again: ";
        cin >> count;
    }

    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        cout << "\nAppliance #" << i + 1 << endl;

        cout << "Name: ";
        getline(cin, appliances[i]);

        cout << "Wattage (watts): ";
        cin >> watts[i];

        while (watts[i] < 0)
        {
            cout << "Invalid wattage. Enter again: ";
            cin >> watts[i];
        }

        cout << "Hours used per day: ";
        cin >> hours[i];

        while (hours[i] < 0)
        {
            cout << "Invalid hours. Enter again: ";
            cin >> hours[i];
        }

        cin.ignore();
    }

    cout << "\nData successfully saved.\n";
}

void computeUsage(double watts[], double hours[],
    int count, double& totalUsage)
{
    totalUsage = 0;

    for (int i = 0; i < count; i++)
    {
        totalUsage += (watts[i] / 1000.0) * hours[i];
    }

    cout << "\nElectricity usage successfully computed.\n";
}

// DISPLAY REPORT
void displayReport(double totalUsage, double savingsGoal)
{
    const double ratePerKwh = 12.0;

    double totalCost = totalUsage * ratePerKwh;

    cout << fixed << setprecision(2);

    cout << "\n===== ELECTRICITY REPORT =====\n";
    cout << "Total Usage: " << totalUsage << " kWh\n";
    cout << "Estimated Cost: PHP " << totalCost << endl;
    cout << "Savings Goal: PHP " << savingsGoal << endl;

    if (totalCost <= savingsGoal)
    {
        cout << "\nCongratulations! You are within your savings goal.\n";
    }
    else
    {
        cout << "\nYour electricity cost exceeds your savings goal.\n";
        cout << "Recommendation:\n";
        cout << "- Reduce appliance usage hours\n";
        cout << "- Turn off unused appliances\n";
        cout << "- Use energy-efficient devices\n";
    }
}

void showAppliances(string appliances[], double watts[],
    double hours[], int count)
{
    cout << "\n===== APPLIANCE LIST =====\n";

    if (count == 0)
    {
        cout << "No appliance data available.\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << "\nAppliance #" << i + 1 << endl;
        cout << "Name: " << appliances[i] << endl;
        cout << "Wattage: " << watts[i] << " W" << endl;
        cout << "Hours Used: " << hours[i] << " hours\n";
    }
}

void saveUserData(string currentUser, string appliances[],double watts[], double hours[], int count, double totalUsage, double savingsGoal)
{
    ofstream outFile("users.txt", ios::app);

    const double ratePerKwh = 12.0;
    double totalCost = totalUsage * ratePerKwh;

    outFile << "\n=====================================\n";
    outFile << "USER DATA\n";
    outFile << "=====================================\n";

    outFile << "Username: " << currentUser << endl;
    outFile << "Savings Goal: PHP " << savingsGoal << endl;

    outFile << "\nAPPLIANCES:\n";

    for (int i = 0; i < count; i++)
    {
        outFile << "\nAppliance #" << i + 1 << endl;
        outFile << "Name: " << appliances[i] << endl;
        outFile << "Wattage: " << watts[i] << " W" << endl;
        outFile << "Hours Used: " << hours[i] << " hours" << endl;
    }

    outFile << "\nTOTAL USAGE: "
        << totalUsage
        << " kWh" << endl;

    outFile << "ESTIMATED COST: PHP "
        << totalCost
        << endl;

    if (totalCost <= savingsGoal)
    {
        outFile << "STATUS: Within savings goal\n";
    }
    else
    {
        outFile << "STATUS: Exceeded savings goal\n";
    }

    outFile << "=====================================\n";

    outFile.close();

    cout << "\nUser data saved to users.txt\n";
}
