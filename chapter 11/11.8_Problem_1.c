#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char temp[10];
    char expr[50];
} Code;

int main() {
    Code code[] = {
        {"t1", "a + b"},
        {"t2", "a + b"},
        {"t3", "t1 * c"},
        {"t4", "a + b"}
    };

    int n = 4;
    Code optimized[MAX];
    int optCount = 0;

    // Track already computed expressions
    char knownExpr[MAX][50];
    char knownTemp[MAX][10];
    int knownCount = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < knownCount; j++) {
            if (strcmp(code[i].expr, knownExpr[j]) == 0) {
                // Expression already computed
                strcpy(optimized[optCount].temp, code[i].temp);
                sprintf(optimized[optCount].expr, "%s", knownTemp[j]); // reuse temp
                optCount++;
                found = 1;
                break;
            }
        }

        if (!found) {
            // New expression, keep it
            strcpy(optimized[optCount].temp, code[i].temp);
            strcpy(optimized[optCount].expr, code[i].expr);
            // Save for later matches
            strcpy(knownExpr[knownCount], code[i].expr);
            strcpy(knownTemp[knownCount], code[i].temp);
            knownCount++;
            optCount++;
        }
    }

    // Output optimized code
    printf("✅ Optimized Code:\n");
    for (int i = 0; i < optCount; i++) {
        if (strchr(optimized[i].expr, ' ') != NULL) // real expression
            printf("%s = %s\n", optimized[i].temp, optimized[i].expr);
        else // just assign from previous temp
            printf("%s = %s\n", optimized[i].temp, optimized[i].expr);
    }

    return 0;
}
