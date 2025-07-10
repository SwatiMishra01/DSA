https://leetcode.com/problems/jump-game/description/
LEETCODE-55

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxIndx=0;
        for(int i=0; i<n; i++){
            if(i>maxIndx)
            return false;
            maxIndx=max(i+nums[i],maxIndx);
        }
        return true;
        
    }
};
T.C=O(N)
S.C=O(1)
