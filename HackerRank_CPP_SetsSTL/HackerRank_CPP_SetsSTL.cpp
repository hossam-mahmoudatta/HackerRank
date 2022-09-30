
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    set<int> list; //Creates a set of integers.
    int numberOfQueries;
    int QueryType;
    int dataValue;
    

    cin >> numberOfQueries;

    for (int i = 0; i < numberOfQueries; i++) {
        
        cin >> QueryType >> dataValue;
        set<int>::iterator opIterator = list.find(dataValue);

        if (QueryType == 1) {
            list.insert(dataValue);
            //cout << "Insert\n";
        }
        else if (QueryType == 2) {

            /*
            for (opIterator = list.begin(); opIterator != list.end(); opIterator++) {
                cout << *opIterator << " ";
            }
            */
            //opIterator = list.begin();
            //cout << endl;

            if ( opIterator != list.end() ) {
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



