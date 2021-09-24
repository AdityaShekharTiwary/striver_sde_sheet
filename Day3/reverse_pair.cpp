int reversePairs(vector<int> &nums, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((long long)nums[i] > (long long)2 * nums[j]) cnt++;
        }
    }
    return cnt;
}