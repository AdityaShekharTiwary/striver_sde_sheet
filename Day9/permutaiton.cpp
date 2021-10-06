class Solution {
public:

    vector<vector<int>> res;
    vector<int> temp;
    vector<int> vis;

    void backtrack(vector<int> nums, int n, int idx) {
        if (temp.size() == n) {
            res.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                temp.push_back(nums[i]);
                backtrack(nums, n, i + 1);
                vis[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vis.resize(n, 0);
        backtrack(nums, n, 0);
        return res;
    }
};