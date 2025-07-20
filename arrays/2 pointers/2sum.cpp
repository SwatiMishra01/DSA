--------------------------------------------
          BRUTE FORCE
  --------------------------------------------
  class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == target - nums[i]) {
                    return {i, j};
                }
            }
        }
        // Return an empty vector if no solution is found
        return {};
    }
};


--------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------------
              HASH MAP
  -----------------------------------------
  class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //curr+x=target
        //x=target-curr
        int n=nums.size();

        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]=i;
        }

        for(int i=0; i<n; i++){
            int x=target -nums[i];
            if(mp.find(x)!=mp.end() && mp[x]!=i){
                return{i,mp[x]};
            }
        }
        return {};
    }
};
