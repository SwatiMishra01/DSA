https://leetcode.com/problems/majority-element/description/
leetcode-169

//Boyer-Moore Voting Algorithm hai, jo majority element find karta hai in optimal O(n) time and O(1) space.
//i	  nums[i]	result	count	Action
// 0	2	       2	   1	Init
// 1	2	       2	   2	Same as result → count++
// 2	1	       2	   1	Different → count--
// 3	1	       2	   0	Different → count-- → reset
// 4	1	       1	   1	New candidate → 1
// 5	2	       1	   0	Different → reset again
// 6	2	       2	   1	New candidate → 2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result=nums[0];
        int count=1;
        for(int i=0; i<nums.size(); i++){
             //If nums[i] is the same as res, increase the count (supports our candidate).
            //If nums[i] is different from res, decrease the count (opposes our candidate).
      if(nums[i]==result)
      count++;
        else
        count--;
        if(count==0){
            result=nums[i];
            count=1;
        }
        }
        return result;
    }
};
