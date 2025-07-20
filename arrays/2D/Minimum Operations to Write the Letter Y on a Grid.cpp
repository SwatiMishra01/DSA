https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid/description/
LEETCODE-3071

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int c0=0, c1=0, c2=0; // counts for 0/1/2 in 'Y' cells

        // TOP-LEFT to CENTER diagonal (main diagonal)
        for(int i=0, j=0; i<n/2 && j<n/2; i++, j++){
            if(grid[i][j]==0) c0++;
            if(grid[i][j]==1) c1++;
            if(grid[i][j]==2) c2++;
        }

        // TOP-RIGHT to CENTER diagonal (secondary diagonal)
        for(int i=0, j=n-1; i<n/2 && j>n/2; i++, j--){ // note: j > n/2 avoids center overlap
            if(i==j) continue; // skip center overlap
            if(grid[i][j]==0) c0++;
            if(grid[i][j]==1) c1++;
            if(grid[i][j]==2) c2++;
        }

        // VERTICAL line from center downward
        for(int i=n/2, j=n/2; i<n; i++){
            if(grid[i][j]==0) c0++;
            if(grid[i][j]==1) c1++;
            if(grid[i][j]==2) c2++;
        }

        // Vector to store frequency of 0/1/2 in Y-shape
        vector<int> c; 
        c.push_back(c0); c.push_back(c1); c.push_back(c2);
        int cum = c0+c1+c2; // Total Y-cells

        // Count total number of 0, 1, 2 in grid
        int s0=0, s1=0, s2=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) s0++;
                if(grid[i][j]==1) s1++;
                if(grid[i][j]==2) s2++;
            }
        }

        // Subtract Y counts to get NON-Y counts
        s0 -= c0; 
        s1 -= c1; 
        s2 -= c2;

        // Vector to store frequency of 0/1/2 in NON-Y cells
        vector<int> s; 
        s.push_back(s0); s.push_back(s1); s.push_back(s2);
        int sum = s0+s1+s2; // Total NON-Y cells

        // Try all combinations:
        // Assign value `i` to Y-cells, value `j` to NON-Y-cells (i ≠ j)
        int ans = INT_MAX;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i==j) continue; // must assign different values
                int changesInY = cum - c[i];     // change all Y cells not equal to i
                int changesInRest = sum - s[j];  // change all non-Y cells not equal to j
                ans = min(ans, changesInY + changesInRest);
            }
        }

        return ans;
    }
};
©leetcode
