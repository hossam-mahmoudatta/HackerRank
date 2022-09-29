
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    vector<int> unsortedList;
    int numberOfIntegers;
    int dataValues;

    //cout << "Please enter the number of integers: ";
    cin >> numberOfIntegers;

    for (int i = 0 ; i < numberOfIntegers ; i++) {
        cin >> dataValues;
        unsortedList.push_back(dataValues);
    }

    sort(unsortedList.begin(), unsortedList.end());
    cout << endl;

    for (int i = 0; i < unsortedList.size() ; i++) {
        cout << unsortedList[i] << " ";
    }

    return 0;
}
