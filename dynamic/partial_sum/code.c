#include <stdio.h>
#include <stdbool.h>

// ビット全探索：O(N*2^N)
bool isPartialSum1(int a[], int N, int W) {
    for (int bit = 0; bit < 1 << N; bit++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (bit & 1 << i) sum += a[i];
            if (sum == W) return true;
        }
    }
    return false;
}

// ビット全探索：O(NW)
bool isPartialSum2(int a[], int N, int W) {
    bool dp[N + 1][W + 1];
    for (int i = 0; i < N + 1; i++) { for (int j = 0; j < W + 1; j++) {dp[i][j] = false;} }
    dp[0][0] = true;
    for (int i = 1; i < N + 1; i++) 
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = dp[i - 1][j] | (j >= a[i - 1] & dp[i - 1][j - a[i - 1]]);
    return dp[N][W];
}

int main(void)
{
    int N = 4, W = 10;
    int a[] = {1, 2, 4, 5};

    printf("isPartialSum1: %d\n", isPartialSum1(a, N, W));
    printf("isPartialSum2: %d\n", isPartialSum2(a, N, W));
    return 0;
}