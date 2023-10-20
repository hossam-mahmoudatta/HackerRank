// HackerRank_PS(Intermediate)_TaskPairing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;


int taskOfPairing(vector <int> freq) {
    int freq_size = freq.size();
    
    long pairsCounter = 0;

    long prevRemainder = 0;

    for (int i = 0; i < freq_size; i++) {
        if (freq[i] == 0) {
            prevRemainder = 0;
            continue;
        }

        freq[i] += prevRemainder;
        pairsCounter += freq[i] / 2;
        prevRemainder = freq[i] % 2;
    }

    return (int) pairsCounter;

}


/*
int taskOfPairing(const vector<int>& freq) {
    int pairs = 0;
    int remainingSingles = 0;

    for (int i = 0 ; i < freq.size() ; i++) {
        pairs += freq[i] / 2;  
        // Calculate the number of complete pairs that can be formed
        
        remainingSingles += freq[i] % 2;
        // Track the number of singles remaining

        if (remainingSingles >= 2) {
            // If there are at least two singles, we can form another pair
            pairs++;
            remainingSingles -= 2;
        }
    }
    return pairs;
}
*/

int main() {
    // Example usage
    vector<int> freq = { 5, 6, 2};
    int size = freq.size();
    long maxPairs = taskOfPairing(freq);
    cout << "Maximum number of pairs: " << maxPairs << endl;

    return 0;
}

