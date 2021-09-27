/*
TC : O(N)
SC : O(1)
Approach : max from left and right
*/



class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left, right;
        int curr = INT_MIN;
        for (int i = 0; i < n; i++) {
            curr = max(curr, height[i]);
            left.push_back(curr);
        }
        curr = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            curr = max(curr, height[i]);
            right.push_back(curr);
        }
        reverse(right.begin(), right.end());
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += min(left[i], right[i]) - height[i];
        }
        return sum;
    }
};