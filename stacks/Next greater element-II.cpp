https://leetcode.com/problems/next-greater-element-ii/description/
LEETCODE-503
-------------------------------------------
  APPROACH 1-> NRUTE FORCE
--------------------------------------------

  class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,-1);
        for(int i=0; i<n; i++){
            for(int j=i+1; j< i+n; j++){
               if(nums[j%n]>nums[i]){
                  res[i]=nums[j%n];
                  break;
               }
            }
        }
        return res;
    }
};
T.C=O(N^2)
S.C=O(N)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------
  APPROACH 2-> MONOTONIC STACK
----------------------------------------
  class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,-1);
        stack<int>st;

        for(int i=2*n-1; i>=0; i--){
            int num=nums[i%n];
            while(!st.empty() && st.top()<=num){
                st.pop();
            }
            if(i<n){
            if(!st.empty()){
                 res[i]=st.top();
               }
           }
           st.push(num);
        }
        return res;
    }
};
T.C=O(N)
S.C=O(N)
