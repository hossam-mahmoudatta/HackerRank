
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>

int main() {
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

	/*
		1. Prints the *p
		Apple
		2. Prints the **p
		A
		3. Prints the *p++
		Banana
	*/
}