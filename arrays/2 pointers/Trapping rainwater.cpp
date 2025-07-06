https://leetcode.com/problems/trapping-rain-water/description/
LEETCODE-42
---------------------
  BRUTE FORCE (TLE)
----------------------

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int sum=0;
        for(int i=0; i<n; i++){
         int lmax=0;
         int rmax=0;

            //lmax k liye loop -> 0 to i
            for(int j=0; j<=i;j++){
               lmax=max(lmax,height[j]);
            }

                //rmax k liye loop i to n-1
                for(int k=i; k<n; k++){
                    rmax=max(rmax,height[k]);
                }

         int ht=min(lmax,rmax);
         sum+=ht-height[i];
        }

          return sum;
        
    }
};

T.C=O(N^2)
S.C=O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------
   BETTER APPROACH- Prefix-Max & Suffix-Max
  --------------------------------
  class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lmax(n,0);
        vector<int>rmax(n,0);
        lmax[0]=height[0];
        rmax[n-1]=height[n-1];
        int ans=0;
        //for lmax
       for(int i=1; i<n; i++){
       lmax[i]=max(lmax[i-1],height[i]);
       }

        //for rmax
        for(int i=n-2; i>=0; i--){
       rmax[i]=max(rmax[i+1],height[i]);
       }


        //for area 
        for(int i=0; i<n; i++){
      ans+=min(lmax[i],rmax[i])-height[i];
        }
        return ans;
    }
};

T.C=O(N)
S.C=O(N)+O(N)=O(N)

---------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------
   2 POINTER
  -----------------------------
  class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lmax=0;
        int rmax=0;
        int sum=0;
        //2 pointers
        int l=0;
        int r=n-1;
        while(l<r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);

            if(lmax<rmax){
            sum+=lmax-height[l];
            l++;
            }
            else
            {
            sum+=rmax-height[r];
            r--; 
            }
        }
       
        return sum;
      
    }
};
T.C=O(N)
S.C=O(1)
