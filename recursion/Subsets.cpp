https://leetcode.com/problems/subsets/description/
LEETCODE-78

  Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

  class Solution {
    private:
    void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>&ans ){
        //base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude condition
        solve(nums,output,index+1,ans);

        //include condition
        int element=nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>output;
       int index=0;
       solve(nums,output,index,ans) ;
       return ans;
    }
};
T.C=O(2^n)
S.C=O(2N)
