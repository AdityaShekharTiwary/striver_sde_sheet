class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        multiset<int, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.insert(nums[i]);
            if (pq.size() == k) {
                res.push_back(*pq.begin());
                pq.erase(pq.find(nums[i - k + 1]));
            }
        }
        return res;
    }
};