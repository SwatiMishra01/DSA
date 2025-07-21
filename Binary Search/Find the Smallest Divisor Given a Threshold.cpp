https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
LEETCODE-1283
-------------------------
     BRUTE FORCE
--------------------------


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        for (int d=1; d<=maxi; d++){
            int sum=0;
            for(int i=0; i<n; i++){
                sum+=ceil((double)nums[i]/(double)d);
            }

            if(sum<=threshold)
            return d;
        }
        return -1;
    }
};
T.C=O(max(arr[])*N)
S.C=O(1)

--------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------
      BINARY SEARCH
  ---------------------------
  class Solution {
public:
 
 int f(vector<int>& nums,int div){
             int sum=0;
            for(int i=0; i<nums.size(); i++){
                sum+=ceil((double)nums[i]/(double)div);
            }
            return sum;
 }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        //base case
        if(n>threshold) return -1;


        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            if(f(nums,mid)<=threshold) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};
T.C=O(log(max(arr[]))*N)
S.C=O(1)
