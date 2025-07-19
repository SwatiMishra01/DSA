https://leetcode.com/problems/sqrtx/description/
LEETCODE-69
  ---------------------------------------
             BRUTE FORCE
  ----------------------------------------
  class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        for(long long i=1; i<=x; i++){
            long long val=i*i;
            if(val<=x*1LL)  ans=i;
            else break;
        }
        return ans;
        
    }
};
T.C=O(X)
S.C=O(1)


-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------
         BINARY SEARCH
  --------------------------------------
  class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        long long int ans=-1;
        while(s<=e){
           long long int mid=s+(e-s)/2;
           long long int square=mid*mid;
           if(square==x) return  mid;
           else if(square<x){
            ans=mid;
            s=mid+1;
           }
           else e=mid-1;
        }
        return ans;
    }
};
T..C=O(X LOG X)
S.C=O(1)
  
