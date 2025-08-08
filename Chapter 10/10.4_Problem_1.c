#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1, tempCount = 1;

void push(char* str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1, j = 0;

    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];
        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            top--; // remove '('
        } else if (isOperator(ch)) {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = stack[top--];
            stack[++top] = ch;
        }
    }

    while (top != -1)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';
}

void generateTAC(char* postfix) {
    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            push(operand);
        } else if (isOperator(ch)) {
            char* op2 = pop();
            char* op1 = pop();
            char temp[10];
            sprintf(temp, "t%d", tempCount++);
            printf("%s = %s %c %s\n", temp, op1, ch, op2);
            push(temp);
        }
    }
}

int main() {
    char infix[100], postfix[100];
    printf("Enter expression (e.g., a + b * c - d / e):\n");
    fgets(infix, sizeof(infix), stdin);

    infixToPostfix(infix, postfix);
    generateTAC(postfix);

    return 0;
}
