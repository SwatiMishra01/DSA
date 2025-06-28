
             HOUSE ROBBERY II ( LEETCODE-213)

# https://leetcode.com/problems/house-robber-ii/description/?envType=problem-list-v2&envId=dynamic-programming
------------------------  QUESTION---------------------------------------------------------------------------------
// 🔸 Problem Understanding (House Robber II):
// Ek thief ko houses rob karne hain, but:
// CONDITIONS:
          // Adjacent houses rob nahi kar sakta.
         // First and last house adjacent maane jaate hain (circular array).
        // Goal: Maximum amount churaana without breaking the adjacent rule.
  ----------------------------------------------------IDEA----------------------------------------------------

  
🧠 Key Idea:
Agar array circular hai (first & last adjacent), toh:
    -Either first house churaoge (but last skip hoga)
    -Or last house churaoge (but first skip hoga)

So, do cases banenge:
    - Rob houses from index 0 to n-2 (skip last)
    - Rob houses from index 1 to n-1 (skip first)
In dono cases ka max answer final result hoga.

-------------------------------------------------APPROACH----------------------------------------------------------------------
  🔧 solve() Function Working (Normal House Robber DP):
Yeh function linear (non-circular) house robbery solve karta hai:

-> prev1 = max loot till previous house
-> prev2 = max loot till one before previous house
-> For every house:
         - incl = prev2 + nums[i] (loot current)
         - excl = prev1 (skip current)
         - ans = max(incl, excl)
         - Update prev2 and prev1
--------------------------------------------------------------------------------------------------------------------------------
  📦 Time and Space Complexity:
Time: O(N)
Space: O(N) (due to space optimized DP)
--------------------------------------------------------------------------------------------------------



class Solution {
int solve(vector<int>& nums){
     int n=nums.size();
    int prev2=0;
    int prev1=nums[0];

    for(int i=1; i<n; i++){
        int incl= prev2+nums[i];
        int excl=prev1+0;

        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}


public:
    int rob(vector<int>& nums) {
           int n=nums.size();
        //base case
        if(n==1)
        return nums[0];
     

       
       vector<int>first;
       vector<int>second;
        for(int i=0; i<n; i++){
            if(i!=n-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                second.push_back(nums[i]);
            }
        }
        return max(solve(first),solve(second));
    }
};



-----------------------------------------------------------------------------------------------------------------------------------------------

                                                         HOUSE ROBBERY (LEETCODE-198)
------------------------------------------------------------------------------------------------------------------------------------------------
          only difference- the houses are not circularly connected
          so no need of splitting in first and second
# https://leetcode.com/problems/house-robber/description/?envType=problem-list-v2&envId=dynamic-programming







class Solution {
int solve(vector<int>& nums){
     int n=nums.size();
    int prev2=0;
    int prev1=nums[0];

    for(int i=1; i<n; i++){
        int incl= prev2+nums[i];
        int excl=prev1+0;

        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}


public:
    int rob(vector<int>& nums) {
        return solve(nums);
    }
};
