/*
TC : O(2^N)
SC : O(N)
Approach : Recursion
*/


void subset(vector<int>arr, vector<int> &res, int n, int idx, int sum) {
    if (idx == n) {
        res.push_back(sum);
        return;
    }

    //picking the element
    subset(arr, res, n, idx + 1, sum + arr[idx]);
    // Not picking the element
    subset(arr, res, n, idx + 1, sum);
}


vector<int> subsetSums(vector<int> arr, int n)
{
    vector<int> res;
    subset(arr, res, n, 0, 0);
    sort(res.begin(), res.end());
    return res;
}