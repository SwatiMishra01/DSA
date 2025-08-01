https://leetcode.com/problems/longest-common-prefix/
LEETCODE-14
------------------------
   BRUTE FORCE
------------------------
  class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != ch)
                    return ans;
            }
            ans += ch;
        }
        return ans;
    }
};
T.C=O(N*M*M)
S.C=O(1)

--------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------
    OPTIMAL
  -----------------
  class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(), strs.end());
        int n=strs.size();
        string first=strs[0];
        string last=strs[n-1];
        for(int i=0; i<min(first.size(),last.size()); i++){
            if(first[i]!=last[i]) return ans;
            ans+=first[i];
        }
        return ans;

    }
};
T.C=O(N log N + M)
S.C=O(1)
