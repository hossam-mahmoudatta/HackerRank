// HackerRank_PS(Intermediate)_MaxSubArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <cmath>
using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

long maxSubarrayValue(int n, int* arr) {
    long MAX = 0;

    // Negate odd indexed elements
    for (int i = 1; i < n; i += 2) {
        arr[i] = 0 - arr[i];
    }

    long maxSoFar = arr[0];
    long currMax = arr[0];
    long currMin = arr[0];
    long minSoFar = arr[0];

    for (int i = 1; i < n; i++) {
        currMax = max(arr[i], currMax + arr[i]);
        maxSoFar = max(maxSoFar, currMax);
        if (currMin > 0)
            currMin = arr[i];
        else
            currMin += arr[i];

        minSoFar = min(minSoFar, currMin);
    }

    MAX = abs(maxSoFar) > abs(minSoFar) ? abs(maxSoFar) : abs(minSoFar);

    return MAX * MAX;
}

int main() {
    int n = 7;
    // int arr[] = { 2, -3, 4, -1, 2 };
    int arr[] = { -7, 5, -1, -4, -10, -8, 10 };
    long result = maxSubarrayValue(n, arr);
    std::cout << "Maximum subarray value: " << result << std::endl;

    return 0;
}