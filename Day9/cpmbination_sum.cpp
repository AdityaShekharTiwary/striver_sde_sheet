class Solution {
public:

    vector<int> temp;
    vector<vector<int>> res;

    void backtrack(vector<int> nums, int n, int idx, int rem) {
        if (rem == 0) {
            res.push_back(temp);
            return ;
        }
        else {
            for (int i = idx; i < n; i++) {
                if (i > idx && nums[i] == nums[i - 1]) continue;
                if (rem < 0) return ;
                temp.push_back(nums[i]);
                backtrack(nums, n, i + 1, rem - nums[i]);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        backtrack(candidates, n, 0, target);
        return res;
    }
};