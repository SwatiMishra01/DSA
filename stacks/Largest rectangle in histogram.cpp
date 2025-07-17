https://leetcode.com/problems/largest-rectangle-in-histogram/description/
LEETCODE-84- (HARD)

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n);  // Next smaller element (default to n)
        vector<int> pse(n, -1); // Previous smaller element (default to -1)

        // Finding NSE (Next Smaller Element)
        stack<int> st1;
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && heights[st1.top()] >= heights[i]) {
                st1.pop();
            }
            if (!st1.empty()) {
                nse[i] = st1.top();
            }
            st1.push(i);
        }

        // Finding PSE (Previous Smaller Element)
        stack<int> st2;
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && heights[st2.top()] >= heights[i]) {
                st2.pop();
            }
            if (!st2.empty()) { 
                pse[i] = st2.top();
            }
            st2.push(i);
        }

        // Compute maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }

        return maxArea;
    }
};
T.C=O(n) + O(n) + O(n) = O(n)
S.C=O(n) + O(n) = O(n)
