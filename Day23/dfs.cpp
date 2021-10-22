vector<int> res;

void dfs(vector<bool> &vis, int node, vector<int> adj[]) {
    vis[node] = true;
    res.push_back(node);
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(vis, it, adj);
        }
    }
}

vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    res.clear();
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(vis, i, adj);
        }
    }
    return res;
}