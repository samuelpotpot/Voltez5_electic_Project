#include <iostream>
#include "functions.h"
#include "display.h"

using namespace std;

const float RATE = 13.80;

void inputData(string names[], float watts[], float hours[], int size) {
    for(int i = 0; i < size; i++) {

        cout << "\nAppliance " << i+1 << " name: ";
        cin >> names[i];

        cout << "Wattage (W): ";
        cin >> watts[i];

        if(watts[i] < 0) {
            cout << "Invalid wattage! Try again.\n";
            i--;
            continue;
        }

        cout << "Hours used per day: ";
        cin >> hours[i];

        if(hours[i] < 0) {
            cout << "Invalid hours! Try again.\n";
            i--;
        }
    }
}

void computeUsage(float watts[], float hours[], float usage[], int size, float &total) {
    total = 0;

    for(int i = 0; i < size; i++) {
        usage[i] = (watts[i] / 1000) * hours[i];
        total += usage[i];
    }

    cout << "Computation complete!\n";
}

void displayReport(string names[], float usage[], float hours[], int size, float total, float userSavings) {

    float cost = total * RATE;
    float reducedUsage = total * 0.80;
    float newCost = reducedUsage * RATE;
    float savingsgoal = cost - newCost;

    cout << "\n--- Usage Report ---\n";

    for(int i = 0; i < size; i++) {
        cout << names[i] << ": " << usage[i] << " kWh/day\n";
    }

    cout << "\nTotal Usage: " << total << " kWh/day\n";
    cout << "Estimated Cost: PHP " << cost << endl;

    cout << "\n--- Savings Analysis ---\n";
    cout << "Your Goal: PHP " << savingsgoal << endl;
    cout << "Your Savings: PHP " << userSavings << endl;

    cout << "\n--- Recommendation ---\n";

    if(savingsgoal <= userSavings && savingsgoal > 0) {
        cout << "- Your goal is achievable!\n";
    }
    else if(userSavings < savingsgoal) {
        cout << "- Reduce usage of high-watt appliances.\n";
    }
    else {
        cout << "- Maintain current usage.\n";
    }

    for(int i = 0; i < size; i++) {
        if(hours[i] > 8) {
            cout << "- Reduce usage time of " << names[i] << endl;
        }

        if(names[i] == "aircon") {
            cout << "- Set aircon to 24-26°C\n";
        }
        else if(names[i] == "tv") {
            cout << "- Turn off TV when not in use\n";
        }
        else if(names[i] == "fan") {
            cout << "- Use fan instead of aircon\n";
        }
    }
}

void showAppliances(string names[], int size) {
    cout << "\nCurrent Appliances:\n";

    bool empty = true;

    for(int i = 0; i < size; i++) {
        if(names[i] != "") {
            cout << "- " << names[i] << endl;
            empty = false;
        }
    }

    if(empty) {
        cout << "(No appliances yet)\n";
    }
}
