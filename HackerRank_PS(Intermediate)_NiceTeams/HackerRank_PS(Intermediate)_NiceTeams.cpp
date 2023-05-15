// HackerRank_PS(Intermediate)_NiceTeams.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <algorithm>

int maxPairs(const std::vector<int>& rating, int minDiff) {
    int n = rating.size();
    int pairs = 0;

    // copy the input inside a new vector
    std::vector<int> sortedRating = rating;
    
    // Sort the ratings in non-decreasing order
    std::sort(sortedRating.begin(), sortedRating.end());

    // Find pairs with a difference of at least minDiff
    for (int i = 0; i < n; i++) {              
        for (int j = i + 1; j < n - 1 ; j++) {

            // the whole logic
            if (sortedRating[j] - sortedRating[i] >= minDiff) {
                pairs++;
            }
        }
    }
    return pairs;
}

int main() {
    // Example usage
    std::vector<int> rating = { 3, 4, 5, 2, 1, 1 };
    int minDiff = 3;
    int maxPairsCount = maxPairs(rating, minDiff);
    std::cout << "Maximum number of pairs: " << maxPairsCount << std::endl;

    return 0;
}



/*
if (n >= 1 && n <= 100000) {
        if (minDiff >= 0 && minDiff <= 1000000000) {
            for (int i = 0; i < n; i++) {
                if (rating[i] >= 1 && rating[i] <= 1000000000) {
                    for (int j = i + 1; j < n - 1 ; j++) {
                        if (sortedRating[j] - sortedRating[i] >= minDiff) {
                            pairs++;
                        }
                    }
                }
            }
        }
    }

*/