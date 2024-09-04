#include <stdio.h>

int main() {
    int n, i;
    float arr[100];

    printf("Enter the number of elements (up to 100): ");
    scanf("%d", &n);

    if (n > 100) {
        printf("Error: Too many elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float largest = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    printf("The largest element in the array is: %.2f\n", largest);

    return 0;
}