class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res;
        int n = temp.size();
        stack<pair<int, int>> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.size() == 0) {
                res.push_back(0);
            }
            else {
                while (st.size() != 0 && st.top().first <= temp[i]) st.pop();
                if (st.size() == 0) {
                    res.push_back(0);
                }
                else res.push_back(st.top().second - i);
            }
            st.push({temp[i], i});
        }
        reverse(res.begin(), res.end());
        return res;
    }
};