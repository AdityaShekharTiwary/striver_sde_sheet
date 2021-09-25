/*
TC : O(N)
SC : O(N)
Approach : Set
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int curr = 0, curr_max = 0;
        for (auto n : st) {
            if (!st.count(n - 1)) {
                curr = 1;
                while (st.count(n + 1)) {
                    curr++;
                    n++;
                }
                curr_max = max(curr, curr_max);
            }
        }
        return curr_max;
    }
};