class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>> &images, vector<vector<bool>> &vis, int i, int j, int newcolor, int curr_color) {
        if (i < 0 || i >= n || j < 0 || j >= m || images[i][j] != curr_color || vis[i][j] == true) return;
        images[i][j] = newcolor;
        vis[i][j] = true;
        dfs(images, vis, i + 1, j, newcolor, curr_color);
        dfs(images, vis, i - 1, j, newcolor, curr_color);
        dfs(images, vis, i, j + 1, newcolor, curr_color);
        dfs(images, vis, i, j - 1, newcolor, curr_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        dfs(image, vis, sr, sc, newColor, image[sr][sc]);
        return image;

    }
};