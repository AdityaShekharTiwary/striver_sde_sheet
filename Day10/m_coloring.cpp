bool isValid(bool graph[101][101], int node, int color, int n, vector<int> &col) {
    for (int j = 0; j < n; j++) {
        if (graph[j][node] == 1 && col[j] == color) return false;
    }
    return true;
}

bool dfs(int node, bool graph[101][101], int m, int n, vector<int> &col) {
    if (node == n) return true;

    for (int i = 1; i <= m; i++) {
        if (isValid(graph, node, i, n, col)) {
            col[node] = i;
            dfs(node + 1, graph, m, n, col);
            col[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> col(n, 0);
    if (dfs(0, graph, m, n, col)) return true;
    return false;
}