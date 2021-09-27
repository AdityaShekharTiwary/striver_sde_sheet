/*
TC : O(N)
SC : O(1)
Approach : Swapping
*/



class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[j]) {
                swap(arr[++j], arr[i]);
            }
        }
        return j + 1;
    }
};