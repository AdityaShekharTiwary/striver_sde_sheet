/*
TC : O(M*N)
SC : O(M*N)
Approach : DP
*/

int cnt(int i, int j, int m, int n, vector<vector<int>> &dp) {
    if (i == m - 1 && j == n - 1) return 1;
    if (i >= m || j >= n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    else return dp[i][j] = cnt(i + 1, j, m, n, dp) + cnt(i, j + 1, m, n, dp);
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return cnt(0, 0, m, n, dp);
}