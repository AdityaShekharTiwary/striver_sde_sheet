/*
TC : O(N)
SC : O(N)
Approach : Hashing
*/


int findDuplicate(vector<int> &nums, int n) {
    vector<bool> arr(n + 1, false);
    for (int i = 0; i < n; i++) {
        if (arr[nums[i]]) return nums[i];
        else arr[nums[i]] = true;
    }
    return -1;
}

/*
TC : O(N)
SC : O(1)
Approach : Multiplying element by -1

*/


int findDuplicate(vector<int> &nums, int n) {
    for (int i = 0; i < n; i++) {
        int idx = abs(nums[i]) - 1;
        nums[idx] = nums[idx] * -1;
        if (nums[idx] > 0) return abs(nums[i]);
    }
    return -1;
}
