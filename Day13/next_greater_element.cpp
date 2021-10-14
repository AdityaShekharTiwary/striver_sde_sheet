vector<long long> nextLargerElement(vector<long long> arr, int n) {
    vector<long long> res(n, -1);
    stack<long long> st;
    for (int i = n - 1; i >= 0; i--) {
        if (st.size() == 0) {
            st.push(arr[i]);
        }
        else {
            while (st.size() != 0 && st.top() < arr[i]) {
                st.pop();
            }
            if (st.size() == 0) res[i] = -1;
            else res[i] = st.top();
            st.push(arr[i]);
        }
    }
    return res;
}