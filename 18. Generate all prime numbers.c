#include <stdio.h>

void generatePrimes(int n) {
    int prime[n + 1];
    for (int i = 0; i <= n; i++) {
        prime[i] = 1; // Assume all numbers are prime initially
    }

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == 1) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = 0; // Mark multiples of p as non-prime
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the maximum number to generate primes: ");
    scanf("%d", &n);

    printf("Prime numbers up to %d are: ", n);
    generatePrimes(n);

    return 0;
}
