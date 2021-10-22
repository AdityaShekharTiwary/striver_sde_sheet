class Solution
{
public:
	//Function to return list containing vertices in Topological order.

	void dfs(int node, vector<int> &res, vector<bool> &vis, vector<int> adj[]) {
		vis[node] = true;
		for (auto it : adj[node]) {
			if (!vis[it]) {
				dfs(it, res, vis, adj);
			}
		}
		res.push_back(node);
	}

	vector<int> topoSort(int n, vector<int> adj[])
	{
		vector<int> res;
		vector<bool> vis(n, false);
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				dfs(i, res, vis, adj);
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};