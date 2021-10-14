class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                st.push(')');
                continue;
            }
            if (c == '{') {
                st.push('}');
                continue;
            }
            if (c == '[') {
                st.push(']');
                continue;
            }
            // cout<<st.top()<<" "<<c<<endl;
            else if (c != '(' || c != '{' || c != '[') {
                if (st.size() == 0 || st.top() != c) return false;
                else st.pop();
            }

        }
        return st.size() == 0 ;
    }
};