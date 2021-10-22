bool dfs(int node, int parent, vector<bool> &vis, vector<int> adj[]) {
    vis[node] = true;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(it, node, vis, adj)) return true;
        }
        else {
            if (it != parent) return true;
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[]) {
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, vis, adj)) return true;
        }
    }
    return false;
}