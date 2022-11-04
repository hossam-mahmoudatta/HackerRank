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
	double p = ((tri.a + tri.b + tri.c) / 2.0);
	double S = sqrt(p * (p - tri.a) * (p - tri.b) * (p - tri.c));
	return S;
}
void sort_by_area(triangle* tr, int n) {
	// Sort an array a of the length n
	triangle temp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1 ; j < n; j++) {
			if (area(tr[i]) > area(tr[j])) {
				temp = tr[i];
				tr[i] = tr[j];
				tr[j] = temp;
			}
		}
	}
	printf("The areas i have are: \n");
	for (int i = 0; i < n; i++) {
		printf("%f ", area(tr[i]));
	}
	printf("\n");
	/*
		if (s[i] > s[i + 1]) {
			temp->a = tr[i + 1].a;
			temp->b = tr[i + 1].b;
			temp->c = tr[i + 1].c;

			tr[i + 1].a = tr[i].a;
			tr[i + 1].b = tr[i].b;
			tr[i + 1].c = tr[i].c;

			tr[i].a = temp->a;
			tr[i].b = temp->b;
			tr[i].c = temp->c;
		}
	*/
	/*
		if (s[i] > s[i + 1]) {
			temp->a = tr[j].a;
			temp->b = tr[j].b;
			temp->c = tr[j].c;

			tr[j].a = tr[i].a;
			tr[j].b = tr[i].b;
			tr[j].c = tr[i].c;

			tr[i].a = temp->a;
			tr[i].b = temp->b;
			tr[i].c = temp->c;
			break;
		}
	*/
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