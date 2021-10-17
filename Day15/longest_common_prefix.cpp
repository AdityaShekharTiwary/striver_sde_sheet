class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if (str.size() == 1) return str[0];
        map<string, int> hash;
        for (auto it : str) {
            string t = "";
            for (auto x : it) {
                t += x;
                hash[t]++;
            }
        }

        string ans = "";
        int curr_max = str.size();
        for (auto it : hash) {
            if (it.second >= curr_max) {
                curr_max = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};