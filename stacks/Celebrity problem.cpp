https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

----------------------------------
  APPROACH 1-> BRUTE FORCE
----------------------------------

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n=mat.size();
        vector<int>knowMe(n,0);
        vector<int>Iknow(n,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue; // ❗ skip self-checks
                if(mat[i][j]==1){
                    knowMe[j]++;
                    Iknow[i]++;
                }
            }
        }
        
        for(int i=0; i<n;i++){
            if(knowMe[i]==n-1 && Iknow[i]==0)
            return i;
        }
        return -1;
        
        
    }
};
T.C=O(N^2)
S.C=O(2N) ~O(N)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------
 APPROACH 2->
------------------------------------
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n - 1;

        // Step 1: Find potential celebrity
        while (top <down) {
            if (mat[top][down] == 1)
                top++; // top knows down => top is not celeb
            else
                down--; // top doesn't know down => b is not celeb
        }

        int candidate = top;

        // Step 2: Verify candidate
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                return -1;
        }

        return candidate;
    }
};
T.C=O(2N)
S.C=O(1)
