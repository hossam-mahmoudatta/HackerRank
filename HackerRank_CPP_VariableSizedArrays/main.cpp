// HackerRank_CPP_VariableSizedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    //cout << "*****      Welcome to the Variable Sized Arrays Problem       *****\n\n";
    int n = 0, q, k, i = 0, j = 0;
    int value = 0;
    int indexValue = 0;
    int queryIndexValue = 0;
    
    vector < vector<int> > sizeableArray; // 2D Vector
    
    cin >> n >> q;

    for (i = 0; i < n; i++) {
        cin >> k;
        vector <int> rows;

        if (k >= 1 && k <= 3 * pow(10, 5)) {
            for (j = 0; j < k; j++) {
                cin >> value;
                rows.push_back(value);
            }
        }
        else {
            return 1;
        }
        sizeableArray.push_back(rows);
    }

    //cout << "\nExecuting Queries\n\n";
    // All the time is spent here
    // Must come up with a fast algorithm to search for the number

    for (int a = 0; a < q; a++) {
        cin >> indexValue >> queryIndexValue;

        cout << sizeableArray[indexValue][queryIndexValue];
        cout << "\n";
        
    }
    return 0;
}


*/