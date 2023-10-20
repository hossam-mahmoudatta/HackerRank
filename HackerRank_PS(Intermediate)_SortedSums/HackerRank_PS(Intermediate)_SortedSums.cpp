// HackerRank_PS(Intermediate)_SortedSums.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007; // 1,000,000,007

int sortedSum(const vector<int>& a) {
    
    int inputSize = a.size();
    
    // a new vector to take a copy of a
    vector<int> sorted(a.begin(), a.end());

    long long sum = 0;
    // Using long long to avoid overflow during computations

    for (int i = 0; i < inputSize; i++) {
        long long fi = 0;  // Current f(i) value
        
        // This piece of algorithm will sort as I increase 
        sort(sorted.begin(), sorted.begin() + i + 1);

        for (int j = 0; j <= i; j++) {
            fi = fi + (j + 1) * sorted[j];
        }
        sum = (sum + fi); // Add the partial sum to the overall sum
    }
    
    sum = sum % MOD;
    
    // Convert the sum to int before returning
    return static_cast<int>(sum);  
}

int main() {
    // Example usage
    //vector<int> a = { 9, 5, 8};
    vector<int> a = { 989605, 554335, 938146, 420327, 573599, 674780, 226418, 80001, 589043, 194195 };
    int result = sortedSum(a);
    cout << "Result: " << result << endl;

    return 0;
}