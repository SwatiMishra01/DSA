https://leetcode.com/problems/combination-sum-iii/description/
LEETCODE-216
  
class Solution {
    void f(int k,int start, int count,int target,vector<vector<int>>&op,vector<int>&ans){
        if(count==k && target==0) {
            op.push_back(ans);
            return;
        }

        if(count>k || target<0) return;
        for(int i=start; i<=9; i++){
            ans.push_back(i);
            f(k,i+1,count+1,target-i,op,ans);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>op;
        vector<int>ans;
        f(k,1,0,n,op,ans);
        return op;
    }
};
T.C=O(2^N)
S.C=O(N)
