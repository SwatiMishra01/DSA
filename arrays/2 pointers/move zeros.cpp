https://leetcode.com/problems/move-zeroes/
283-leetcode


  ------------------------
  Shift-fill
  --------------------
  class Solution {
public:
    void moveZeroes(vector<int>& nums) {
int j=0;
        int n=nums.size();
        for (int i=0; i<n;i++){
        //sare non-zero element ko shuru m daaldo bhai
        
        if(nums[i]!=0){
            nums[j]=nums[i]; //If nums[i] is non-zero, it goes to nums[j] and j moves ahead.
            j++;
        }

        }
        //for zeros 
        for(int i=j; i<n; i++){
            nums[i]=0; //the remaining indices from j to n-1 are filled with zeros.
        }
    }
};

T.C=O(N)
S.C=O(1)
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------
   Swap-based two-ptr
  -----------------------
  class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;  // Next position for non-zero

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != j) {
                    swap(nums[i], nums[j]);
                }
                j++;
            }
        }
    }
};
T.C=O(N)
S.C=O(1)

