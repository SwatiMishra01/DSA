https://leetcode.com/problems/subsets-ii/description/
LEETCODE-90

-------------------------
 BRUTE FORCE
-----------------------
class Solution {
public:
void f(vector<int>& nums,int i,vector<int>&ds, set<vector<int>>&res){
        if(i==nums.size()){
            res.insert(ds);
            return;
        }

        //pick
        ds.push_back(nums[i]);
        f(nums,i+1,ds,res);

        //backtrack
        ds.pop_back();

        //not pick
         f(nums,i+1,ds,res);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>res;
        vector<int>ds;
        f(nums,0,ds,res);
        

        for(auto it=res.begin(); it!=res.end(); it++){
            ans.push_back(*it);
        }
        return ans;

    }
};
T.C=O( 2^n *(k log (x) )). 2^n
S.C=O( 2^n *k )


--------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------
   OPTIMAL APPROACH
  -----------------------------
  class Solution {
public:
void f(vector<int>& nums,int ind,vector<int>&ds, vector<vector<int>>&ans){
         ans.push_back(ds);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            f(nums,i + 1, ds, ans);
            ds.pop_back();
         }
      }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        f(nums,0,ds,ans);
        return ans;

    }
};
T.C=O(2^n * k)
S.C=O(2^n * k)
