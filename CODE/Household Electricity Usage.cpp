#include <iostream>
#include "Main.h"
#include "Database.h"

using namespace std;

int main()
{
    int startChoice;
    string currentUser;

    cout << "=========================================\n";
    cout << " HOUSEHOLD ELECTRICITY USAGE CALCULATOR\n";
    cout << "=========================================\n";

    cout << "\n1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter choice: ";
    cin >> startChoice;

    switch (startChoice)
    {
    case 1:
        registerUser();
        break;

    case 2:
        if (!login(currentUser))
        {
            return 0;
        }
        break;
    
    default:
       cout<< "Invalid choice." << endl;
        return 0;
    }

     
         // LOGIN AFTER REGISTER
         if (startChoice == 1)
         {
             cout << "\nPlease login to continue.\n";

             if (!login(currentUser))
             {
                 return 0;
             }
         }

     string appliances[MAX];
     double watts[MAX];
     double hours[MAX];

     int count = 0;
     int choice;

     double totalUsage = 0;
     double savingsGoal;

     cout << "\nWelcome, " << currentUser << "!" << endl;

     cout << "Enter your desired daily savings (PHP): ";
     cin >> savingsGoal;

     do
     {
         cout << "\n========== MENU ==========\n";
         cout << "1. Input Appliance Data\n";
         cout << "2. Compute Electricity Usage\n";
         cout << "3. Display Report\n";
         cout << "4. Show Appliances\n";
         cout << "5. Save User Data\n";
         cout << "6. Exit\n";
         cout << "Enter choice: ";
         cin >> choice;

         switch (choice)
         {
         case 1:
             inputData(appliances, watts, hours, count);
             break;

         case 2:
             computeUsage(watts, hours, count, totalUsage);
             break;

         case 3:
             displayReport(totalUsage, savingsGoal);
             break;

         case 4:
             showAppliances(appliances, watts, hours, count);
             break;

         case 5:
             saveUserData(currentUser, appliances, watts, hours, count, totalUsage, savingsGoal);
             break;

         case 6:
             cout << "\nExiting program...\n";
             break;

         default:
             cout << "\nInvalid choice.\n";
         }

     } while (choice != 5);

     return 0;
}
