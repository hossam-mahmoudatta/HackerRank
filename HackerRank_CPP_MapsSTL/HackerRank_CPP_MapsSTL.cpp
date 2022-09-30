#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    map <string, int> schoolDatabase;
    int numberOfQueries;
    int QueryType;
    int dataValue;
    string dataString;
    //cout << "Number of Queries: ";
    cin >> numberOfQueries;
    //cout << "\n";

    for (int i = 0; i < numberOfQueries; i++) {
        //cout << "Query Type: ";
        cin >> QueryType;
        map<string, int>::iterator opIterator; //= schoolDatabase.find(dataValue); // define the iterator to find a specfic value.
    
        if (QueryType == 1) {
            //cout << "Insert String & grade\n";
            cin >> dataString >> dataValue;
            
            opIterator = schoolDatabase.find(dataString);
            if (opIterator != schoolDatabase.end()) {
                // If the operator when scanning from the beginning of the list
                // didnt reach till the end because it found the value, then this if condition is satisfied
                //cout << "Found The Element\n";
                opIterator->second += dataValue;
                //cout << opIterator->second << "Yes\n";
            }
            else {
                schoolDatabase.insert(make_pair(dataString, dataValue));
                //cout << "Insert\n";
            }
            //cout << "\n";
        }
        else if (QueryType == 2) {
            //map<string, int>::iterator itr = m.find(val); //Gives the iterator to the element val if it is found otherwise returns m.end() .
            //map<string, int>::iterator itr = m.find("Maps"); //If Maps is not present as the key value then itr==m.end().
            //cout << "Insert String\n";
            cin >> dataString;

            opIterator = schoolDatabase.find(dataString);
            if (opIterator != schoolDatabase.end()) {
                // If the operator when scanning from the beginning of the list
                // didnt reach till the end because it found the value, then this if condition is satisfied
                //cout << "Found The Element\n";
                schoolDatabase.erase(opIterator);
                //cout << "Erased\n";
            }
            else {
                //cout << "Not Erased\n";
            }
            //cout << "\n";
        }
        else if (QueryType == 3) {
                
            //cout << "Insert String\n";
            cin >> dataString;

            opIterator = schoolDatabase.find(dataString);
            if (opIterator != schoolDatabase.end()) {
                //cout << "Yes\n";
                cout << opIterator -> second << "\n";
            }
            else {
                cout << "0\n";
            }
            //cout << "\n";
        }
    }
    return 0;
}



