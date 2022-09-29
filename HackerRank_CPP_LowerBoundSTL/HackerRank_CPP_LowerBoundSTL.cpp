
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    vector<int> list;
    int numberOfIntegers; // Number of integers you want to enter
    int dataValue; // the value itself entered
    int numberOfQueries;
    int queryValue;
    
    cin >> numberOfIntegers;

    for (int i = 0; i < numberOfIntegers; i++) {
        cin >> dataValue;
        list.push_back(dataValue);
    }

    sort(list.begin(), list.end());

    cin >> numberOfQueries;

    // The problem is that this logic or any other logic doesn't work on this IDE, but works on the website's IDE
    for (int i = 0; i < numberOfQueries; i++) {
        
        cin >> queryValue;
        // Creating a vector with iterator to store lower_bound() in it 
        // what is an iterator?
        vector<int>::iterator tempBound = lower_bound(list.begin(), list.end(), queryValue);
        
        if (queryValue != *tempBound) {
            // Because i can't debug this code here on this IDE, I will guess that *tempBound
            // Stores the same value of queryValue and its index, after executing lower_bound
            cout << "No " << ( tempBound - list.begin() + 1 ) << endl;
        }
        else {
            cout << "Yes " << (tempBound - list.begin() + 1) << endl;
        }
        
    }
    return 0;
}


/*
    // 2nd Algorithm
    for (int i = 0; i < numberOfQueries; i++) {
        cin >> queryValue;
        vector<int>::iterator tempBound = lower_bound(list.begin(), list.end(), queryValue);
        int testVariable = (tempBound - list.begin());

        if (list.at(testVariable) == queryValue) {
          cout << "Yes " << testVariable + 1 << endl;
        }
        else {
            cout << "No " << testVariable + 1 << endl;
        }
    }
*/