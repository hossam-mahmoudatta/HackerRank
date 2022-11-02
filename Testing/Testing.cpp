
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>

int main() {
	
	printf("Size of the array of strings: \n");
	int n;
	scanf("%d", &n);

	char** arr;
	arr = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; i++) {
		*(arr + i) = (char*)malloc(1024 * sizeof(char));
		scanf("%s", *(arr + i));
		*(arr + i) = (char*)realloc(*(arr + i), strlen(*(arr + i)) + 1);
	}
	
	char* temp;
	temp = (char*)malloc(1 * sizeof(char*));
	//printf("Temp: %s\n", temp);
	
	printf("Printing now the array of strings: \n");

	for (int i = 1; i < n; i++) {
		temp = arr[i - 1];
		printf("\n%d: %s\n", (i + 1), *(arr + i)); // reading whats inside the address place
		printf("Printing now characters of the word: \n");
		
		for (int j = 0; j < strlen(*(arr + i)); j++) {
			// *(&arr[j] + i) actually prints garbage in the place of the characters
			// Turns out that *((*(arr + i)) + j) is what will print the chars inside the string
			// And turns out that arr[i][j] works too!
			// To explain, *(arr + i) means arr[i]
			// And *((*(arr + i)) + j) means arr[i][j]
			
			if (temp)

			printf("%d.%d: %c\n", (i + 1), (j + 1), *((*(arr + i)) + j));
		}
		//printf("Temp: %c %c\n", temp[2], temp[3]);
		// Now that i know how to access everything using pointers
		// I now need to compare
		
	}
}





/*
	char** p;
	p = (char**)malloc(100);
	p[0] = (char*)"Apple";      // or write *p, points to location of 'A'
	p[1] = (char*)"Banana";     // or write *(p+1), points to location of 'B'

	printf("1. Prints the *p\n");
	printf("%s\n", *p); //Prints the first pointer location until it finds '\0'
	printf("2. Prints the **p\n");
	printf("%c\n", **p); //Prints the exact character which is being pointed
	*p++;                        //Increments for the next string
	printf("3. Prints the *p++\n");
	printf("%s\n", *p);


		1. Prints the *p
		Apple
		2. Prints the **p
		A
		3. Prints the *p++
		Banana
	*/