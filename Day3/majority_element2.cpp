/*
TC : O(N)
SC : O(N)
Approach : Hashmap
*/



#include<bits/stdc++.h>
vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    map<int, int> hash;
    vector<int> res;
    for (int i = 0; i < n; i++) hash[arr[i]]++;
    for (auto it : hash) {
        if (it.second > n / 3) res.push_back(it.first);
    }
    return res;

}

/*
TC : O(N)
SC : O(1)
Approach : Moore Voting Algo
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int num1 = -1e9, num2 = -1e9, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == num1) cnt1++;
            else if (arr[i] == num2) cnt2++;
            else if (cnt1 == 0) {
                num1 = arr[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0) {
                num2 = arr[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == num1) cnt1++;
            if (arr[i] == num2) cnt2++;
        }
        vector<int> res;
        if (cnt1 > n / 3) res.push_back(num1);
        if (cnt2 > n / 3) res.push_back(num2);
        return res;
    }
};