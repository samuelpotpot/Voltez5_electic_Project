#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;

void inputData(string names[], float watts[], float hours[], int size);
void computeUsage(float watts[], float hours[], float usage[], int size, float &total);

#endif
