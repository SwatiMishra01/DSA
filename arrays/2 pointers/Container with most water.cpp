https://leetcode.com/problems/container-with-most-water/description/
LEETCODE-11

------------------------------------
  BRUTE FORCE  (TLE)
-------------------------------------
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxi=0;
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                int width=j-i;
                int ht=min(height[i],height[j]);
                int area=width*ht;
                maxi=max(maxi,area);
            }
        }
        return maxi;
    }
};

T.C=O(N^2)
S.C=O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------
                2 POINTERS
  -----------------------------------------
  class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int maxi=0;
      while(i<j){
                int width=j-i;
                int ht=min(height[i],height[j]);
                int area=width*ht;
                maxi=max(maxi,area);

                if(height[i]<height[j])
                 i++;
                 else
                  j--;
            }
        return maxi;
    }
};
T.C=O(N)
S.C=O(1)
-----------------------------------------------------------------------------------------------------------------------------------------------------------
