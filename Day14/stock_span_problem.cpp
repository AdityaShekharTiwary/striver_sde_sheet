vector <int> calculateSpan(int price[], int n)
{
    vector<int> res;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        while (st.size() != 0 && st.top().first <= price[i]) {
            cnt += st.top().second;
            st.pop();
        }
        st.push({price[i], cnt});
        res.push_back(cnt);
    }
    return res;
}