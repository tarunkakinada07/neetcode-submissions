class Solution {
public:

    vector<int> nsi(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> psi(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> left = psi(heights);
        vector<int> right = nsi(heights);

        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {

            int width = right[i] - left[i] - 1;
            int length = heights[i];

            max_area = max(max_area, width * length);
        }

        return max_area;
    }
};