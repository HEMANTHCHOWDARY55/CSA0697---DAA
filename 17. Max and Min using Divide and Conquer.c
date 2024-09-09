#include <stdio.h>

struct Result {
    int max;
    int min;
};

struct Result findMaxMin(int arr[], int low, int high) {
    struct Result result, leftResult, rightResult;
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;
    leftResult = findMaxMin(arr, low, mid);
    rightResult = findMaxMin(arr, mid + 1, high);

    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    return result;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Result result = findMaxMin(arr, 0, size - 1);

    printf("Maximum value is: %d\n", result.max);
    printf("Minimum value is: %d\n", result.min);

    return 0;
}
