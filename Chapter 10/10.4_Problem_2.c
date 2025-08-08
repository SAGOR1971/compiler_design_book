#include <stdio.h>

int main() {
    int label = 1, temp = 1;

    // Simulated input
    char condVar1 = 'a', condVar2 = 'b';
    char thenLHS = 'x', thenOp1 = 'y', thenOp2 = 'z';
    char elseOp1 = 'y', elseOp2 = 'z';

    printf("if %c <= %c goto L%d\n", condVar1, condVar2, label); // Inverse condition
    printf("t%d = %c + %c\n", temp, thenOp1, thenOp2);
    printf("%c = t%d\n", thenLHS, temp);
    temp++;
    printf("goto L%d\n", label + 1);
    printf("L%d:\n", label);
    printf("t%d = %c - %c\n", temp, elseOp1, elseOp2);
    printf("%c = t%d\n", thenLHS, temp);
    printf("L%d:\n", label + 1);

    return 0;
}
