https://leetcode.com/problems/cherry-pickup-ii/

full explanation-> https://www.naukri.com/code360/library/cherry-pickup
-------------------------------------------
   APPROACH 1-> RECURSION   (TLE)
 ---------------------------------------
class Solution {
public:

int f(int i, int j1, int j2,int n,int m,vector<vector<int>>& grid ){
    //base cases

    //1->out of bounds
    if(j1<0 || j1>=m || j2<0 || j2>=m)
    return -1e9;  //since it is a maximum problem return min 
                  // so that it will not consider this path

    // 2-> destination
    if(i==n-1){
    //2 possibilities->they end up in same cell or different cell
    if(j1==j2)
    return grid[i][j1];

    else
    return grid[i][j1]+grid[i][j2];
    }

    //recursive relation->move alice and bob simultaneously
    //exploring all paths
    int maxi=-1e9; //since a maximum problem
    for(int dj1=-1; dj1<=+1; dj1++){
        for(int dj2=-1; dj2<=+1; dj2++){

            if(j1==j2)
               maxi=max(maxi,grid[i][j1]+f(i+1,j1+dj1,j2+dj2,n,m,grid));
            else
               maxi=max(maxi,grid[i][j1]+grid[i][j2]+ f(i+1,j1+dj1,j2+dj2,n,m,grid));

        }
    }
    return maxi;


}
    int cherryPickup(vector<vector<int>>& grid) {
     int n=grid.size(); //rows
     int m=grid[0].size(); //columns
        return f(0,0,m-1,n,m,grid);


    }
};


T.C=(3^N + 3^N)
S.C=O(N)
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

----------------------------------------------
   APPROACH 2-> MEMOIZATION
----------------------------------------------
  class Solution {
public:

int f(int i, int j1, int j2,int n,int m,vector<vector<int>>& grid,
                                   vector<vector<vector<int>>>&dp ){
    //base cases

    //1->out of bounds
    if(j1<0 || j1>=m || j2<0 || j2>=m)
    return -1e9;  //since it is a maximum problem return min 
                  // so that it will not consider this path

    // 2-> destination
    if(i==n-1){
    //2 possibilities->they end up in same cell or different cell
    if(j1==j2)
    return grid[i][j1];

    else
    return grid[i][j1]+grid[i][j2];
    }


    //applying memoization
    if(dp[i][j1][j2]!=-1)
    return dp[i][j1][j2];


    //recursive relation->move alice and bob simultaneously
    //exploring all paths
    int maxi=-1e9; //since a maximum problem
    for(int dj1=-1; dj1<=+1; dj1++){
        for(int dj2=-1; dj2<=+1; dj2++){

            if(j1==j2)
               maxi=max(maxi,grid[i][j1]+f(i+1,j1+dj1,j2+dj2,n,m,grid,dp));
            else
               maxi=max(maxi,grid[i][j1]+grid[i][j2]+ f(i+1,j1+dj1,j2+dj2,n,m,grid,dp));

        }
    }
    return dp[i][j1][j2]= maxi;


}
    int cherryPickup(vector<vector<int>>& grid) {
     int n=grid.size(); //rows
     int m=grid[0].size(); //columns

     //int dp[row][col][col]
     vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,n,m,grid,dp);


    }
};

T.C=O(N*M*M)
 S.C=O(N*M*M)+O(N)

  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------------
        APPROACH 3-> TABULATION
  --------------------------------------------
  class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // STEP 1: Create 3D DP table dp[i][j1][j2]
        // i = current row
        // j1 = Alice's column
        // j2 = Bob's column
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        // STEP 2: Initialize base case (last row)
        // If both robots reach last row, take cherries:
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) {
                    dp[n-1][j1][j2] = grid[n-1][j1];
                } else {
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }

        // STEP 3: Fill DP table from bottom to top
        // i goes from n-2 to 0 (second last row to first row)
        for (int i = n-2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {

                    int maxi = INT_MIN;  // initialize max cherries for current cell

                    // STEP 4: Try all 3x3 possible moves
                    // Alice can move left/straight/right => dj1 = -1, 0, +1
                    // Bob can move left/straight/right => dj2 = -1, 0, +1
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            // Check if new positions are inside grid
                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {

                                int val = 0;

                                // STEP 5: Collect cherries from current cell
                                if (j1 == j2) {
                                    // Both robots on same cell: take cherry once
                                    val = grid[i][j1];
                                } else {
                                    // Different cells: take both
                                    val = grid[i][j1] + grid[i][j2];
                                }

                                // STEP 6: Add best from next row
                                val += dp[i+1][nj1][nj2];

                                // STEP 7: Store maximum possible cherries
                                maxi = max(maxi, val);
                            }
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        // STEP 8: Final answer -> start from (0,0) and (0,m-1)
        return dp[0][0][m-1];
    }
};

T.C = States * Time per state
    = (n * m * m) * 9
    = O(n * m^2 * 9)
S.C=O(n * m^2)
  //DP table dp[n][m][m] use hota hai.

