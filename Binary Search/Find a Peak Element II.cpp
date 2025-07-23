https://leetcode.com/problems/find-a-peak-element-ii/description/
LEETCODE-1901

----------------------------
  BRUTE FROCE
----------------------------
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //all directions
                int up=0;
                if(i-1>=0) up=mat[i-1][j];


                int down=0; 
                if(i+1<n) down=mat[i+1][j];


                int left=0; 
                if(j-1>=0)  left=mat[i][j-1];


                int right=0;
                if(j+1<m)  right=mat[i][j+1];


                if(mat[i][j]>up && mat[i][j]>down && mat[i][j]>left && mat[i][j]>right)
                return {i,j};

            }
        }
        return {-1,-1};
    }
};


  -----------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------
     BINARY SEARCH
  -------------------------
    class Solution {
private:
    int getMax(vector<vector<int>>& mat, int n, int m, int mid){
        int maxi = INT_MIN;
        int col=0;
        for(int i=0; i<m; i++){
            if(mat[mid][i]>maxi){
                maxi = mat[mid][i];
                col = i;
            }
        }
        return col;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int l=0, r=n-1;
        
        // binary search on row
        while(l<=r){
            int mid = l+(r-l)/2;
            int col = getMax(mat,n,m,mid);
            int up,down;
            if(mid-1>=0) up = mat[mid-1][col];
            else up=-1;
            
            if(mid+1<n) down = mat[mid+1][col];
            else down=-1;

            if(mat[mid][col]>up && mat[mid][col]>down){
                return {mid,col};
            }
            else if(mat[mid][col]<=up){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return {-1,-1};
    }
};
