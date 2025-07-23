-----------------
  BRUTE FORCE
  --------------
  class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};
T.C=O(N*M)
S.C=O(1)


-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------
  BINARY SEARCH
  -------------
  class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col= matrix[0].size();
        int rowIndex=0;
        int colIndex=col-1;
        while(rowIndex<row && colIndex>=0){
            int element=matrix[rowIndex][colIndex];
            if (element==target){
                return 1;
            }
            if (element<target){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }
        return 0;
    }
};
T.C=O(N+M)
S.C=O(1)
