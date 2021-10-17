class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) t += s[i];
            else {
                if (t.size() > 0) temp.push_back(t);
                t = "";
            }
        }
        if (t.size() > 0) temp.push_back(t);
        reverse(temp.begin(), temp.end());
        string res = "";
        for (int i = 0; i < temp.size() - 1; i++) {
            res += temp[i];
            res += " ";
        }
        res += temp[temp.size() - 1];
        return res;
    }
};