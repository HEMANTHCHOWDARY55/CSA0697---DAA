#include <stdio.h>

struct Item {
    int weight;
    int value;
};

void knapsackGreedy(struct Item items[], int n, int capacity) {
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", totalValue);
}

int main() {
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    knapsackGreedy(items, n, capacity);

    return 0;
}
