class Solution {
public:
    vector<vector<int>>res;
    vector<int> temp;

    void backtrack(vector<int> nums, int n, int idx) {
        res.push_back(temp);
        for (int i = idx; i < n; i++) {
            if (i == idx || nums[i] != nums[i - 1]) {
                temp.push_back(nums[i]);
                backtrack(nums, n, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        backtrack(nums, n, 0);
        return res;
    }
};