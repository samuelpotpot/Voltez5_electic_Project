#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Appliance {
    string name;
    double watts;
    double hours;
};

string currentUser = "";
