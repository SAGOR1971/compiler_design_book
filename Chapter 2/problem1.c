#include <stdio.h>

int main() {
    int a[100], b[100];  // Assuming arrays have enough elements
    int prod = 0;
    int i;

    // Example initialization (you can modify as needed)
    for (i = 0; i < 100; i++) {
        a[i] = i + 1;
        b[i] = i + 2;
    }

    i = 1;
    while (i <= 20) {
        int t1 = 4 * i;
        int t2 = a[t1];   // Normally you'd do a[i], but using 4*i per given logic
        int t3 = 4 * i;
        int t4 = b[t3];
        int t5 = t2 * t4;
        int t6 = prod + t5;
        prod = t6;

        int t7 = i + 1;
        i = t7;
    }

    printf("Final product sum = %d\n", prod);
    return 0;
}
