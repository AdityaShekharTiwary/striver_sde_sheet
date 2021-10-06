class Solution {
public:
    vector<int> temp;
    vector<vector<int>> res;

    void backtrack(vector<int> nums, int n, int idx, int rem) {
        if (rem < 0) return;
        if (rem == 0) {
            res.push_back(temp);
        }
        for (int i = idx; i < n; i++) {
            temp.push_back(nums[i]);
            backtrack(nums, n, i, rem - nums[i]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        backtrack(candidates, n, 0, target);
        return res;
    }
};