/*
TC : O(N)
SC : O(N)
Approach : Hashing
*/


int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    unordered_map<int, int> hash;
    int sum = 0, curr = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) ans = i + 1;
        if (hash.find(sum) != hash.end()) {
            ans = max(ans, i - hash[sum]);
        }
        else hash[sum] = i;
    }
    return ans;

}