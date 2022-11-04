// Problem Link
// hackerrank.com/challenges/small-triangles-large-triangles/problem?isFullScreen=false

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle {
	int a;
	int b;
	int c;
};
typedef struct triangle triangle;

double area(triangle tri) {
	int a, b, c;
	// The following are given formulas
	// to find the areas
	// The purpose of this function is to
	// achieve a modular design in coding
	double p = ((tri.a + tri.b + tri.c) / 2.0);
	double S = sqrt(p * (p - tri.a) * (p - tri.b) * (p - tri.c));
	return S;
}

void sort_by_area(triangle* tr, int n) {
	// Sort an array a of the length n
	// Creating a temp variable to hold the data for the swap
	triangle temp;

	// i < n - 1 so that i dont access forbidden
	// memory when iterating thru 'j'
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1 ; j < n; j++) {
			if (area(tr[i]) > area(tr[j])) {
				temp = tr[i];
				tr[i] = tr[j];
				tr[j] = temp;
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	triangle* tr = (triangle*)malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}

	sort_by_area(tr, n);
	
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}