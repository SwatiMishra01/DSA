https://leetcode.com/problems/single-number/description/
leetcode-136

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr=0;
        for(int i=0; i<nums.size(); i++){
        xorr=xorr ^ nums[i];
        }
        return xorr;
    }
};

T.C=O(N)
S.C=O(1)
