https://leetcode.com/problems/maximal-rectangle/description/
LEETCODE-85- (HARD)
  class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n), pse(n, -1);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        // Clear stack for next pass
        while (!st.empty()) st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0); // histogram for each row
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            // Build histogram from top to current row
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1; // prefix sum (extend bar)
                else
                    heights[j] = 0; // reset on '0'
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
T.C=O(m * n)
S.C=O(n)
  
