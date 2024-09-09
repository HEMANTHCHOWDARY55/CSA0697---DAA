#include <stdio.h>

void printPascal(int n) {
    for (int line = 0; line < n; line++) {
        int C = 1;
        for (int i = 1; i <= line + 1; i++) {
            printf("%d ", C);
            C = C * (line - i + 1) / i;
        }
        printf("\n");
    }
}

int main() {
    int n = 5;
    printPascal(n);
    return 0;
}
