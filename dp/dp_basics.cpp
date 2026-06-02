#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Basic implementation: Fibonacci using DP tabulation.
int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// Sample Problem 1: Climbing stairs.
// Approach: ways[i] = ways[i-1] + ways[i-2].
int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> ways(n + 1);
    ways[1] = 1;
    ways[2] = 2;
    for (int i = 3; i <= n; i++) ways[i] = ways[i - 1] + ways[i - 2];
    return ways[n];
}

// Sample Problem 2: 0/1 Knapsack (small example).
// Approach: 2D DP over items and capacity.
int knapsack(const vector<int>& wt, const vector<int>& val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }
    return dp[n][W];
}

// Sample Problem 3: Longest Increasing Subsequence (O(n^2)).
// Approach: dp[i] = LIS ending at i.
int lis(const vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dp(nums.size(), 1);
    int ans = 1;
    for (int i = 0; i < (int)nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    cout << "Fib(10): " << fib(10) << "\n";
    cout << "Climb stairs(5): " << climbStairs(5) << "\n";

    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    cout << "Knapsack(W=7): " << knapsack(wt, val, 7) << "\n";

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS length: " << lis(nums) << "\n";
    return 0;
}
