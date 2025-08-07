#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int count = 0, i = 0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        char ch = tolower(input[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        i++;
    }

    printf("Number of vowels: %d\n", count);

    return 0;
}
