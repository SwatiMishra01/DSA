https://leetcode.com/problems/spiral-matrix/description/
LEETCODE-54

  class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, top = 0, right = m - 1, bottom = n - 1;
        vector<int> ans;

        while (left <= right && top <= bottom) {
            // 1 -> move right
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            // 2 -> move down
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // 3 -> move left (check needed)
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            // 4 -> move up (check needed)
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }
        return ans;
    }
};
