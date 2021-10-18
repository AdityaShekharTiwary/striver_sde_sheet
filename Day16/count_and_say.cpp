class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if (n == 1) return res;
        while (--n) {
            string curr = "";
            for (int i = 0; i < res.size(); i++) {
                int cnt = 1;
                while ((i + 1 < res.size()) && res[i] == res[i + 1]) {
                    i++;
                    cnt++;
                }
                curr += to_string(cnt) + res[i];
            }
            res = curr;
        }
        return res;
    }
};