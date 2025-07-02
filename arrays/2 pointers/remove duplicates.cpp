https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
leetcode-26

  --------------------
     BRUTE FORCE
  --------------------
  class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      
       set<int>st;
        for(int num:nums){
            st.insert(num);
        }
        
            int indx=0;
        for(auto it:st){
             nums[indx++] = it;  // Overwrite original array
        }

       return st.size();
    }
};

TC=0(N log N)+O(N)
SC=O(N)
  -------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------
   OPTIMAL-2POINTERS
  ------------------------------
  
  class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int i=0;
      for(int j=1; j<nums.size(); j++){
        if(nums[i]!=nums[j]){
            nums[i+1]=nums[j];
            i++;
        }
      }
      return i+1;
    }
};

TC=O(N)
SC=O(1)
