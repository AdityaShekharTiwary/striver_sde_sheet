/*
TC :- O(N)
SC :- O(N)
Approach :- Hashing
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 1, INT_MAX);
        for (int i = 0; i < n; i++) {
            arr[nums[i]] = -1;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == INT_MAX) return i;
        }
        return -1;
        int sum = n * (n + 1) / 2;
        for (auto it : nums) sum -= it;
        return sum;
    }
};

/*
TC :- O(N)
SC :- O(1)
Approach :- Maths
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (auto it : nums) sum -= it;
        return sum;
    }
};

/*
TC :- O(N)
SC :- O(N)
Approach :- Hashing

*/

// Missing and repeated number

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int, int> ans;
    vector<int> temp(n + 1, 1e6);
    for (int i = 0; i < n; i++) {
        if (temp[arr[i]] == -1) ans.second = arr[i];
        else temp[arr[i]] = -1;
    }
    for (int i = 1; i <= n; i++) {
        if (temp[i] != -1) ans.first = i;
    }
    return ans;

}
