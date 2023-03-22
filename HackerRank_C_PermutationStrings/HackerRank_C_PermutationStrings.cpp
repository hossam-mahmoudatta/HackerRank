// HackerRank_C_PermutationStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int next_permutation(int n, char** s) {
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
}

int main() {
	char** s;
	int n;
	scanf_s("%d", &n);
	s = calloc(n, sizeof(char*));
	
	// Basically from what I understand, is that I will input n
	// Which is the number of strings I will enter.
	// Then I will enter the strings
	// I will basically print the strings in different combinations
	// The trick is that if strings are equal, you don't need to make permutations for them
	// So this task will consume alot of time to process
	// 
	// 
	//

	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}