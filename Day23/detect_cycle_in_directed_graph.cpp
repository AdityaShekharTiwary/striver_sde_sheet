bool dfs(int node, vector<bool> &vis, vector<bool> &dfsVis, vector<int> adj[]) {
    vis[node] = true;
    dfsVis[node] = true;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(it, vis, dfsVis, adj)) return true;
        }
        else if (vis[it] && dfsVis[it]) return true;
    }
    dfsVis[node] = false;
    return false;
}

bool isCyclic(int n, vector<int> adj[]) {
    vector<bool> vis(n, false), dfsVis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(i, vis, dfsVis, adj)) return true;
        }
    }
    return false;
}