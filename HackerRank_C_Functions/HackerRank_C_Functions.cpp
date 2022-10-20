#include <stdio.h>

int max_of_four(int a, int b, int c, int d) {
    int max;
    max = a;
    if (b > a) {
        max = b;
        if (c > b) {
            max = c;
            if (d > c) {
                max = d;
            }
        }
    }
    else if (c > a) {
        max = c;
        if (d > c) {
            max = d;
        }
    }
    else if (d > a) {
        max = d;
    }
    return max;
}


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}