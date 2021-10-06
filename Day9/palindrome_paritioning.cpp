class Solution {
public:

    vector<vector<string>> res;
    vector<string> temp;

    bool isPal(string s, int l, int r) {
        while (l <= r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void backtrack(string s, int n, int idx) {
        if (idx == n) {
            res.push_back(temp);
        }

        for (int i = idx; i < n; i++) {
            if (isPal(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                backtrack(s, n, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        backtrack(s, n, 0);
        return res;
    }
};