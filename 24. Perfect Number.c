#include <stdio.h>

int isPerfectNumber(int num) {
    int sum = 1; // Start with 1 as it's a divisor of all numbers
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectNumber(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}
