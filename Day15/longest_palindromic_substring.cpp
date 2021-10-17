class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        string res = "";
        res = s[0];
        for (int g = 0; g < s.size(); g++) {

            for (int i = 0, j = g; i < s.size(), j < s.size(); i++, j++) {
                if (g == 0) {
                    dp[i][j] = true;
                }
                else if (g == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
                else {
                    // cout<<s[i]<<" "<<s[j]<<endl;
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true) {
                        // cout<<s[i]<<" "<<s[j]<<endl;
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
                if (dp[i][j]) {
                    if (res.size() < j - i + 1) {
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        // for(auto it:dp){
        //     for(auto x:it) cout<<x<<" ";
        //     cout<<endl;
        // }
        return res;
    }
};