class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dir = { -1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        int ans = -1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<int, int> temp = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int row = temp.first + dir[i];
                    int col = temp.second + dir[i + 1];
                    if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if (fresh > 0) return -1;
        if (ans == -1) return 0;
        return ans;

    }
};