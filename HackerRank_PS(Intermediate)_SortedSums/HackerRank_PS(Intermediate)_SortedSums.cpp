// HackerRank_PS(Intermediate)_SortedSums.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int sortedSum(const vector<int>& a) {
    
    int inputSize = a.size();
    
    // a new vector to take a copy of a
    vector<int> sorted(a.begin(), a.end());
    
    // Sort the sequence in non-descending order
    sort(sorted.begin(), sorted.end());  

    long long sum = 0;
    // Using long long to avoid overflow during computations

    for (int i = 0; i < inputSize; i++) {
        long long fi = 0;  // Current f(i) value

        for (int j = 0; j <= i; j++) {
            fi = (fi + (j + 1) * sorted[j]) % MOD;  // Calculate the partial sum for f(i)
        }

        sum = (sum + fi) % MOD;  // Add the partial sum to the overall sum
    }

    return static_cast<int>(sum);  // Convert the sum to int before returning
}

int main() {
    // Example usage
    vector<int> a = { 9, 5, 8};
    //vector<int> a = { 989605, 554335, 938146, 420327, 573599, 674780, 226418, 80001, 589043, 194195 };
    int result = sortedSum(a);
    cout << "Result: " << result << endl;

    return 0;
}