/*
TC : O(N)
SC : O(N)
Approach : Hashmap
Problem : Find count of pair with sum 0
*/

#include<bits/stdc++.h>
int ZeroPairSum(int n, vector<int> arr) {
    map<int, int> hash;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (hash.find(0 - arr[i]) != hash.end()) {
            cnt += hash[0 - arr[i]];
        }
        hash[arr[i]]++;
    }
    return cnt;

}

/*
TC : O(N)
SC : O(N)
Approach : Hashmap
Problem : Return indices of pair with given sum.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(target - nums[i]) != hash.end()) {
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};