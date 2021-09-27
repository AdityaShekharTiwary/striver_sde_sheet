class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        int l = 0, r = 0, ans = 0;
        while (r < n) {
            if (nums[r] == 1) r++;
            else if (nums[r] == 0 && cnt < k) {
                r++;
                cnt++;
            }
            else if (nums[r] == 0 && cnt >= k) {
                while (cnt == k) {
                    if (nums[l] == 0) cnt--;
                    l++;
                }
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};