#include <stdio.h>
#include <stdlib.h>

void update(int* a, int* b) {
    // Complete this function    
    int sum, abso;
    sum = (*a) + (*b);
    abso = (*a) - (*b);
    *a = sum;
    *b = abs(abso);
}

int main() {
    int a, b;
    int *pa = &a;
    int *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}