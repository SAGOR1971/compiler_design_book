#include <stdio.h>
int main() {
 char input[1000];
 char token[100];
 int i = 0;
 int tokenIndex = 0;
 printf("Enter a string to tokenize (end with '$'):\n");
 char ch;
 while ((ch = getchar()) != '$' && i < 999) {
 input[i++] = ch;
 }
 input[i] = '\0';
 printf("\nTokens:\n");
 i = 0;
 while (1) {
 char c = input[i];
 if (c == ' ' || c == ',' || c == '+' || c == '-' || c == '*' ||
 c == '/' || c == '(' || c == ')' || c == '\0') {
 if (tokenIndex > 0) {
 token[tokenIndex] = '\0';
 printf("%s\n", token);
 tokenIndex = 0;
 }
 if (c != ' ' && c != ',' && c != '\0') {
 printf("%c\n", c);
 }
 if (c == '\0') break;
 } else {
 token[tokenIndex++] = c;
 }
 i++;
 }
 return 0;
}
