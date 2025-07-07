https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
LEETCODE-3

  --------------------------
          HASHING
  --------------------------
  class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            int hash[256]={0};
            for (int j=i; j<n; j++){
                   if(hash[s[j]]==1)
                   break;
                   int len=j-i+1;
                   maxLen=max(maxLen,len);
                   hash[s[j]]=1;
            }
        }
        return maxLen;
    }
};

T.C=O(N^2)
S.C=O(256)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------------------------------------
         HASH BUT UPDATED VERSION USING SLIDING WINDOW & 2 POINTERS
  -------------------------------------------------------------------
  class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int maxLen=0;
        int n=s.size();
        int hash[256];
        fill(hash, hash + 256, -1); // Proper initialization
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l)
                l=hash[s[r]]+1;
            }
            int len=r-l+1;
            maxLen=max(maxLen,len);
            hash[s[r]]=r;
            r++;

        }
        return maxLen;
    }
};
T.C=O(N)
S.C=O(256)
  
