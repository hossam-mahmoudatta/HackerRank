/*
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    // I got the data from the string str
    vector<int> extractedNumbers;
    stringstream stringParser(str);
    int numberInput;

    while (stringParser >> numberInput) {
        // the while condition shows that stringParser will put its value into numberInput
        extractedNumbers.push_back(numberInput);
    }
    return extractedNumbers;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
*/