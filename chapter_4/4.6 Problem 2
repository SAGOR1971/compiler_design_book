#include <stdio.h>
int main() {
 char input[1000];
 char word[100];
 int i = 0, j = 0;
 char ch;
 int a_count = 0, an_count = 0, the_count = 0;
 printf("Enter a string (end with '$'):\n");
 while ((ch = getchar()) != '$' && i < 999) {
 input[i++] = ch;
 }
 input[i] = '\0';
 i = 0;
 while (1) {
 ch = input[i];
 if (ch == ' ' || ch == ',' || ch == '.' || ch == '\n' || ch == '\t' || ch == '\0') {
 if (j > 0) {
 word[j] = '\0';
 if ((j == 1) &&
 (word[0] == 'a' || word[0] == 'A')) {
 a_count++;
 }
 else if ((j == 2) &&
 ((word[0] == 'a' || word[0] == 'A')) &&
 (word[1] == 'n' || word[1] == 'N')) {
 an_count++;
 }
 else if ((j == 3) &&
 ((word[0] == 't' || word[0] == 'T')) &&
 (word[1] == 'h' || word[1] == 'H') &&
 (word[2] == 'e' || word[2] == 'E')) {
 the_count++;
 }
 j = 0;
 }
 if (ch == '\0') break;
 } else {
 word[j++] = ch;
 }
 i++;
 }
 printf("\nA - %d\nAn - %d\nThe - %d\n", a_count, an_count, the_count);
 return 0;
}
