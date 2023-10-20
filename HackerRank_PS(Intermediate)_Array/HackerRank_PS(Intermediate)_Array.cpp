// HackerRank_PS(Intermediate)_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

/*
    for (int i = 0; i < arrLength; i++) {
        for (int j = i + 1; j < arrLength; j++) {
            value = arr[i] & arr[j];
            //value = sqrt(value);
            if (value == 0) {
                continue;
            }
            while (value % 2 == 0) {
                value /= 2;
            }
            if (value == 1) {
                counter++;
            }
            value = 0;
        }
    }
    printf("How many pairs? %d", counter);
    printf("\n");
}
*/

using namespace std;

int minOperations(vector<int>& arr, int threshold, int d) {
    map<int, int> freqMap;

    // Count the frequency of remainders after division
    for (int num : arr) {
        int remainder = num % d;
        freqMap[remainder]++;
    }

    int minOperations = 0;
    int totalEqualElements = 0;

    // Iterate through the frequency map
    for (const auto& pair : freqMap) {
        int remainder = pair.first;
        int frequency = pair.second;

        // Calculate the number of operations needed for each remainder
        int operations = (frequency - 1) / threshold;
        minOperations += operations;

        // Calculate the total number of equal elements achieved
        totalEqualElements += operations * threshold;
    }

    // Calculate the remaining elements needed to reach the threshold
    int remainingElements = threshold - totalEqualElements;
    minOperations += remainingElements;

    return minOperations;
}

int main() {
    vector<int> arr = { 64, 30, 25, 33 };
    // vector<int> arr = { 1, 2, 3, 4 };
    int threshold = 2;
    int d = 2;

    int result = minOperations(arr, threshold, d);
    std::cout << "Minimum number of operations: " << result << std::endl;

    return 0;
}