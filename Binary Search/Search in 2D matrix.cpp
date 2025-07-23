https://leetcode.com/problems/search-a-2d-matrix/description/
LEETCODE-74

  --------------------
      BRUTE FORCE
  ---------------------
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==target)
                return true;
            }
        }
        return false;
    }
};
T.C=O(N*M)
S.C=O(1)

---------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------
    BINARY SEARCH
  --------------------------------
  class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=0;
        int e=n*m-1;
        while(s<=e){
            int mid=s+(e-s)/2;
             int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) s = mid + 1;
        else e = mid - 1;
    }
    return false;
    }
};
T.C=O(log(NxM))
S.C=O(1)
