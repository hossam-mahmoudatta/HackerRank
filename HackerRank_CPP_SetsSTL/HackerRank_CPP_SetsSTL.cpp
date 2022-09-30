
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    set<int> list; //Creates a set of integers. sets stores the values inside sorted by itself.
    int numberOfQueries;
    int QueryType;
    int dataValue;
    
    cin >> numberOfQueries;

    for (int i = 0; i < numberOfQueries; i++) {
        
        cin >> QueryType >> dataValue;
        set<int>::iterator opIterator = list.find(dataValue); // define the iterator to find a specfic value.

        if (QueryType == 1) {
            list.insert(dataValue);
            //cout << "Insert\n";
        }
        else if (QueryType == 2) {

            if ( opIterator != list.end() ) {
                // If the operator when scanning from the beginning of the list
                // didnt reach till the end because it found the value, then this if condition is satisfied
                //cout << "Found The Element\n";
                list.erase(dataValue);
                //cout << "Erased\n";
            }
            else {
                //cout << "Not Erased\n";
            }
        }
        else if (QueryType == 3) {
            if (opIterator != list.end()) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
    return 0;
}



















/*
    for (opIterator = list.begin(); opIterator != list.end(); opIterator++) {
        cout << *opIterator << " ";
    }
*/
//opIterator = list.begin();
//cout << endl;