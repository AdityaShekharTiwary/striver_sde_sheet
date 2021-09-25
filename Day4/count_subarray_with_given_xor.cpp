/*
TC : O(NLogN)
SC : O(N)
Appraoch : Hashing

*/

int subarraysXor(vector<int> &arr, int x)
{
    int xr = 0, cnt = 0;
    map<int, int> hash;
    for (auto it : arr) {
        xr = xr ^ it;
        if (xr == x) cnt++;
        if (hash.find(xr ^ x) != hash.end()) {
            cnt += hash[xr ^ x];
        }
        hash[xr]++;
    }
    return cnt;
}