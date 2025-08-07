#include <stdio.h>

int main() {
    char input[100];
    int i = 0, valid = 1;

    printf("Enter a string: ");
    scanf("%s", input);

    while (input[i] != '\0') {
        if (input[i] != '0' && input[i] != '1') {
            valid = 0;
            break;
        }
        i++;
    }

    if (valid)
        printf("Valid binary string.\n");
    else
        printf("Invalid binary string.\n");

    return 0;
}
