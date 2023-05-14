// HackerRank_PS(Intermediate)_LargestArea.cpp : This file contains the 'main' function. Program execution begins and ends there.


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

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int cmp(const void* a, const void* b) {
    
    return *(const int*)a - *(const int*)b;
}

int main() {

    printf("Hello World!\n\n");
   
    int arr[3] = { 0, 2, 4 };
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    int value = 0;
    int counter = 0;
    int base = 2;
    for (int i = 0; i < arrLength; i++) {
        for (int j = i + 1; j < arrLength; j++) {
            value = arr[i] & arr[j];

            if (value == 0) {
                continue;
            }
            while (value % base == 0) {
                value /= base;
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












/*
    So the size of the vector isVERTICAL will determine how many rectangles that i want
    to get out with.
    Algorithm:
    1. I will store the size of of distance vector
    2. I will make conditions with the constraints
    3. i will loop with the size of the distance vector
    4. i will see if i have vertical or horizontal split
    5.

*/

/*
struct Node {
    // this is a binary tree
    int leftBound = 0;
    int rightBound = 0;
    int nodeValue = 0;


    Node(int leftBound, int rightBound, int nodeValue) :
    leftBound(leftBound), rightBound(rightBound), nodeValue(nodeValue) {}

};

void split(Node& node, int x) {


    // Node leftChild;
    // leftChild.leftBound = node.leftBound;
    // leftChild.rightBound = x;
    // leftChild.nodeValue = x - node.leftBound;


    if (x == node.leftBound || x == node.rightBound) {
        // Checks if the Split lies on one of the borders.
        return;
    }
    if (node.leftBound < x && x < node.rightBound) {
        // Checks if the split lies between the borders

        Node leftChild(node.leftBound, x, x - node.leftBound);
        // leftChild creates the new left bound of the split

        Node rightChild(x, node.rightBound, node.rightBound - x);
        // rightChild creates the new right bound of the split

        node.nodeValue = leftChild.nodeValue * rightChild.nodeValue;
        // This reflects b/w parent and child nodes

        split(leftChild, x);
        split(rightChild, x);
    }
}

vector<long> getMaxArea(int width, int height, vector<bool> isVertical, vector<int> distance) {

    Node width_root(0, width, width);
    Node height_root(0, height, height);
    vector<long> ans;

    for (size_t i = 0; i < isVertical.size(); ++i) {
        if (isVertical[i]) {
            split(width_root, distance[i]);
        }
        else {
            split(height_root, distance[i]);
        }
        ans.push_back(width_root.nodeValue * height_root.nodeValue);
    }

    return ans;

}
*/