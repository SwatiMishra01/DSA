https://leetcode.com/problems/sort-colors/
leetcode-75

  -----------------------------
     BRUTE FORCE
  ----------------------------
  class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
    }
};
T.C=O(N LOG N)
S.C=O(1)
---------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------
     BETTER APPROACH ->3 FOR LOOPS
  ---------------------------------
  class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;

        for(int i=0; i<n; i++){
            if(nums[i]==0)  cnt0++;
            else if(nums[i]==1)  cnt1++;
            else  cnt2++;

        }

        //for count 0
        for(int i=0; i<cnt0; i++){
         nums[i]=0;
        }
        
         //for count 1
        for(int i=cnt0; i<cnt0+cnt1; i++){
         nums[i]=1;
        }
         
          //for count 2
        for(int i=cnt0+cnt1; i<n; i++){
         nums[i]=2;
        }
        
    }
};

T.C=O(2N)
S.C=O(1)
  ------------------------------------------------------------------------------------------------------
  -------------------------------------------
    DUTCH NATIONAL FLAG ALGORITHM
  ---------------------------------------------
  class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        // 3 pointers
        int low=0;
        int mid=0;
        int high=n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            

            else if(nums[mid]==1)
                 mid++;


            else {  //where mid==2
             swap(nums[mid],nums[high]);
             high--;
             }
        }
    }
};
T.C=O(N)
S.C=O(1)
