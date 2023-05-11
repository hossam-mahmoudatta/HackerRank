// HackerRank_PS(Basic)_Vowels.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// HackerRank_PS(Basic)_ActiveTrader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <functional>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
 * Complete the 'mostActive' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY customers as parameter.
 */

string findSubstring(string s, int k) {

}

vector <string> mostActive(vector<string> customers) {
    /*
    make a like a map to hold each index and increment if its found before
    then check if the occurences is larger than 5% of the occurences
    then print the name of the key
    */
    map <string, int> occurences;
    vector<string> activeList;

    int vectorSize = customers.size();

    for (int i = 0; i < vectorSize; i++) {
        occurences[customers[i]]++;
    }

    for (const auto& pair : occurences) {
        cout << pair.first << ": " << pair.second << " occurrence(s)" << endl;
        float per = 0;
        per = ((float)(pair.second) / vectorSize) * 100;
        if (per >= 5) {
            activeList.push_back(pair.first);
        }
    }
    return activeList;
}

int main() {
    printf("Hello World!\n");
    printf("How r u\n");
    int numStrings;
    cin >> numStrings;

    string input;
    cin.ignore();
    vector<string> names;

    for (int i = 0; i < numStrings; i++) {
        getline(cin, input);
        names.push_back(input);
    }
    cout << endl;
    vector<string> outputList = mostActive(names);
    sort(outputList.begin(), outputList.end());
    int sizeOutput = outputList.size();

    for (int i = 0; i < sizeOutput; i++) {
        cout << outputList[i] << endl;

    }
    //cout << mostActive(names);

}
