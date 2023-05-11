// HackerRank_PS(Basic)_LongestSubArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <functional>
#include <map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int longestSubarray(vector<int> arr) {
    int arrSize = arr.size();
    int answer = 0;
    int counter = 0;

    for (int i = 0; i < arrSize; i++) {
        unordered_set <int> subArray;
        for (int j = i; j < arrSize; j++) {
            if (subArray.find(arr[j]) != subArray.end()) {
                counter++;
                continue;
            }
            if (subArray.empty()) {
                subArray.insert(arr[j]);
            }
            else if (subArray.size() == 1) {
                if (abs(*subArray.begin() - arr[j]) > 1) {
                    break;
                }
                else {
                    subArray.insert(arr[j]);
                }
            }
            else {
                break;
            }
            counter++;
        }
        answer = max(answer, counter);
    }
    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
