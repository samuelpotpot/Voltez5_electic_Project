#ifndef Main_H
#define Main_H

#include <string>
using namespace std;

const int MAX = 100;


void inputData(string appliances[], double watts[],
    double hours[], int& count);

void computeUsage(double watts[], double hours[],
    int count, double& totalUsage);

void displayReport(double totalUsage, double savingsGoal);

void showAppliances(string appliances[], double watts[], double hours[], int count);

void saveUserData(string currentUser, string appliances[], double watts[], double hours[],int count, double totalUsage, double savingsGoal);

#endif
