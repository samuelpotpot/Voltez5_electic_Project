#include <iostream>
#include "functions.h"
#include "display.h"

using namespace std;

int main() {
    const int SIZE = 5;

    string appliance[SIZE];
    float watts[SIZE] = {0}, hours[SIZE] = {0}, usage[SIZE] = {0};

    float totalUsage = 0;
    float userSavings;
    int choice;

    bool dataEntered = false;
    bool computed = false;

    cout << "Enter your daily savings (PHP): ";
    cin >> userSavings;

    do {
        cout << "\n=== Electricity Usage System ===\n";
        cout << "Savings: PHP " << userSavings << endl;
        cout << "1. Input Appliance Data\n";
        cout << "2. Compute Usage\n";
        cout << "3. Show Report\n";
        cout << "4. Exit\n";

        showAppliances(appliance, SIZE);

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                inputData(appliance, watts, hours, SIZE);
                dataEntered = true;
                computed = false;
                break;

            case 2:
                if(dataEntered) {
                    computeUsage(watts, hours, usage, SIZE, totalUsage);
                    computed = true;
                } else {
                    cout << "Please input data first!\n";
                }
                break;

            case 3:
                if(computed) {
                    displayReport(appliance, usage, hours, SIZE, totalUsage, userSavings);
                } else {
                    cout << "Please compute usage first!\n";
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}
