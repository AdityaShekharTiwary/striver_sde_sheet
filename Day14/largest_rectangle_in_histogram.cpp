class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0), right(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (st.size() == 0) left[i] = 0;
            else {
                while (st.size() != 0 && heights[st.top()] >= heights[i]) st.pop();
                if (st.size() == 0) left[i] = 0;
                else left[i] = st.top() + 1;
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            if (st.size() == 0) right[i] = n - 1;
            else {

                while (st.size() != 0 && heights[st.top()] >= heights[i]) st.pop();
                if (st.size() == 0) right[i] = n - 1;
                else right[i] = st.top() - 1;
            }
            st.push(i);
        }

        // for(auto it:left) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:right) cout<<it<<" ";
        // cout<<endl;
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            max_area = max(max_area, (right[i] - left[i] + 1) * heights[i]);
            // cout<<max_area<<endl;
        }
        return max_area;
    }
};