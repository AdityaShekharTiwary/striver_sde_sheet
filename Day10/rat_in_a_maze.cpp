class Solution {
public:

    vector<string> res;
    string path = "";

    void dfs(vector<vector<int>> &grid, int n, int i, int j, string path) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0) return;
        if (i == n - 1 && j == n - 1) {
            res.push_back(path);
        }

        grid[i][j] = 0;
        dfs(grid, n, i + 1, j, path + "D");
        dfs(grid, n, i, j - 1, path + "L");
        dfs(grid, n, i, j + 1, path + "R");
        dfs(grid, n, i - 1, j, path + "U");
        grid[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &grid, int n) {
        dfs(grid, n, 0, 0, "");
        sort(res.begin(), res.end());
        return res;
    }
};