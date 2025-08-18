https://leetcode.com/problems/longest-consecutive-sequence/description/
LEETCODE-128
  class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans =0;
        int cnt =0;
        sort(nums.begin(),nums.end());
        int n =nums.size();
        if(n==0||n==1) return n;
        for(int i =0; i<n-1; i++){
            if(nums[i]==nums[i+1]) continue;
            if(nums[i+1]-nums[i]==1){
                cnt++;
                 ans =max(cnt,ans);
            }
           if(nums[i+1]-nums[i]!=1){
           
               
                cnt=0;
            }

        }
        return ans+1;
    }
};
T.C=O(N^2)
S.C=O(1)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------
    OPTIMAL
  ---------------------
  class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
    }
};
