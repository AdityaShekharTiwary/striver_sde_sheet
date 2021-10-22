vector<int> bfsOfGraph(int n, vector<int> adj[]) {
    vector<bool> vis(n, false);
    vector<int> res;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        vis[node] = true;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = true;
            }
        }
    }
    return res;
}