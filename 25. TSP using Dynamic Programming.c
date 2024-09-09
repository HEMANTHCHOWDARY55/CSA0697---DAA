#include <stdio.h>
#define INF 9999999
#define N 4

int tsp(int graph[N][N], int dp[N][1 << N], int mask, int pos) {
    if (mask == (1 << N) - 1) {
        return graph[pos][0];
    }
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    int answer = INF;
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAnswer = graph[pos][city] + tsp(graph, dp, mask | (1 << city), city);
            answer = (answer < newAnswer) ? answer : newAnswer;
        }
    }
    return dp[pos][mask] = answer;
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int dp[N][1 << N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
        }
    }

    printf("Minimum cost: %d\n", tsp(graph, dp, 1, 0));
    return 0;
}
