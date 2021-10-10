vector<int> vis;
vector<string> res;
string str;

void backtrack(string s, int n, int idx) {
    if (str.size() == n) {
        res.push_back(str);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            str.push_back(s[i]);
            backtrack(s, n, i + 1);
            vis[i] = 0;
            str.pop_back();
        }
    }
}

vector<string> findPermutations(string &s) {
    str = "";
    int n = s.size();
    vis.resize(n, 0);
    backtrack(s, n, 0);
    return res;
}