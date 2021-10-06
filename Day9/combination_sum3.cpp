class Solution {
public:

    vector<vector<int>> res;
    vector<int> temp;

    void backtrack(int k, int n, int start, int cnt) {
        if (n == 0 && cnt == k) {
            res.push_back(temp);
            return;
        }

        for (int i = start; i <= 9; i++) {
            //if(cnt==k) break;
            temp.push_back(i);
            backtrack(k, n - i, i + 1, cnt + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 1, 0);
        return res;
    }
};