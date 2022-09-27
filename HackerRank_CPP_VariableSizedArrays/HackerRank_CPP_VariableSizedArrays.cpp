// HackerRank_CPP_VariableSizedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

    //cout << "Enter number of vectors followed by number of queries: \n";
    cin >> n >> q;
    //cout << "--> Dynamic Arrays Required: " << n;
    //cout << "\n--> Queries Required: " << q << "\n\n";

    vector < vector<int> > sizeableArray; // 2D Vector
    
    if (( (n >= 1) && ( n <= pow(10, 5) ) ) && ( (q >= 1) && (q <= pow(10, 5) ) )) {
        //cout << "Constraints met.\n";

        for (i = 0 ; i < n ; i++) {
            //cout << "Enter the size of array " << i + 1 << " / " << n << ": ";
            cin >> k;
            vector <int> rows;
            //cout << endl;

            if (k >= 1 && k <= 3 * pow(10, 5)) {
                //cout << "Constraints met.\n";
                for (j = 0 ; j < k ; j++) {
                    //cout << "Enter Element Value: ";
                    cin >> value;
                    //cout << endl;
                    rows.push_back(value);
                }
            }
            else {
                //cout << "Conditions failed.\n";
            }
            //cout << endl;
            //cout << "Array " << i + 1 << " / " << n << " is filled." << endl << endl;
            sizeableArray.push_back(rows);

        }
    }
    else {
        //cout << "Conditions failed.\n";
    }

    /*
    cout << "Printing the Vector\n\n";
    for (int a = 0; a < sizeableArray.size(); a++) {
        
        for (int b = 0; b < sizeableArray[a].size(); b++) {
            cout << sizeableArray[a][b] << " ";
        }
        cout << endl;
    }
    */

    //cout << "\nExecuting Queries\n\n";
    for (int a = 0; a < q; a++) {

        //cout << "Enter the index of the array & the element you want query: ";
        cin >> indexValue >> queryIndexValue;
        //cout << endl;

        if (indexValue < sizeableArray.size()) {
            for (int b = 0 ; b < sizeableArray.size() ; b++) {
                if (b == indexValue) {
                    if (queryIndexValue < sizeableArray[b].size()) {
                        for (int c = 0 ; c < sizeableArray[b].size() ; c++) {
                            if (c == queryIndexValue) {
                                cout << sizeableArray[b][c];
                                cout << "\n";
                            }
                        }
                    }
                }
            }
        }
    }


    //cout << "\nThank you for using the application!\n";
    return 0;
}


