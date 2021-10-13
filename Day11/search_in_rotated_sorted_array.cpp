class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            // found target element
            if (nums[mid] == target) return mid;
            // left part is sorted
            if (nums[mid] >= nums[low]) {
                if (nums[low] <= target && nums[mid] >= target) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            // right part is sorted
            else {
                if (nums[mid] <= target && nums[high] >= target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};