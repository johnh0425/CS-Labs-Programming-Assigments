#include <fstream>
#include <iostream>
#include <cstdlib>
#include<vector>

using namespace std;

void readData(const string &filename, vector<double> &flightA, vector<double> &flightC);
double interpolation(double reqFA, const vector<double> &flightA, const vector<double> &flightC);
bool isOrdered(const vector<double> &flightA);
void reorder(vector<double> &flightA, vector<double> &flightC);
int smallestInd(const vector<double> &flightA, int n);


int main(int argc, char *argv[]) {
    string filename;
    vector<double> flightA;
    vector<double> flightC;
    double reqFA;
    double newCoef;
    string userInput = "Yes";
    
    filename = argv[1];

    readData(filename, flightA, flightC);

    if (!isOrdered(flightA)) {
        reorder(flightA, flightC);
    }
    cout << endl;

    while (userInput == "Yes") {
        cout << "Enter an angle: ";
        cin >> reqFA;
        cout << endl;
        newCoef = interpolation(reqFA, flightA, flightC);
        cout << newCoef << endl;
        cout << "Do you want to continue?" << endl;
        cin >> userInput;
        cout << endl;
    }

    return 0;
}

void readData(const string &filename, vector<double> &flightA, vector<double> &flightC) {
    ifstream inFS;
    double num;
    inFS.open(filename);
    if (!inFS.is_open()) {
      cout << "Error opening " << filename << endl;
      exit(1);
    }
    while (inFS >> num) {
        flightA.push_back(num);
        inFS >> num;
        flightC.push_back(num);
    }
    inFS.close();
}

double interpolation(double reqFA, const vector<double> &flightA, const vector<double> &flightC) {
    double coef;
    int upperBounds;
    int lowerBounds;
    for (unsigned int i = 0; i < flightA.size(); ++i) {
        if (reqFA == flightA.at(i)) {
            return flightC.at(i);
        }
    }

    for (unsigned int i = 0; i < flightA.size(); ++i) {
        if (flightA.at(i) > reqFA) {
            upperBounds = i;
            lowerBounds = i - 1;
            break;
        }
    }
    /* c = flightA.at(upperBounds)
       a = flightA.at(lowerBounds)
       f(c) = flightC.at(upperBounds)
       f(a) = flightC.at(lowerBounds)
       b = reqFA
       f(b) = coef 
       f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a) */

    coef = flightC.at(lowerBounds) + ((reqFA - flightA.at(lowerBounds)) / (flightA.at(upperBounds) - flightA.at(lowerBounds))) * (flightC.at(upperBounds) - flightC.at(lowerBounds));
    return coef;
}

bool isOrdered(const vector<double> &flightA) {
    if (flightA.size() == 0 || flightA.size() == 1) {
        return true;
    }
    for (unsigned int i = 0; i < flightA.size() - 1; ++i) {
        if (flightA.at(i) > flightA.at(i + 1)) {
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &flightA, vector<double> &flightC) {
    int smallInd;
    if (flightA.size() != 0) {
        for (unsigned int i = 0; i < flightA.size() - 1; ++i) {
            smallInd = smallestInd(flightA, i);
            swap(flightA.at(i), flightA.at(smallInd));
            swap(flightC.at(i), flightC.at(smallInd));
        }
    }
}

int smallestInd(const vector<double> &flightA, int nextInd) {
    double index = nextInd; // nextInd = 0, index = 0
    for (unsigned int i = nextInd; i < flightA.size(); ++i) {
        if (flightA.at(index) > flightA.at(i)) {
            index = i;
        }
    }
    return index;
}


