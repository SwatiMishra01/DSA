https://leetcode.com/problems/longest-repeating-character-replacement/description/
LEETCODE-424

  --------------------------
      BRUTE FORCE (TLE)
  --------------------------
  class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxLen=0;
        for(int i=0; i<n; i++){
           int  hash[26]={0};
           int maxFreq=0;
           for(int j=i; j<n; j++){
            hash[s[j]-'A']++;
            maxFreq=max(maxFreq,hash[s[j]-'A']);
            int changes=(j-i+1)-maxFreq;
            if(changes<=k)
            maxLen=max(maxLen,j-i+1);
            else
            break;
           }
        }
        return maxLen;
    }
};

T.C=O(N^2)
S.C=O(26)

--------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------
           SLIDING WINDOW
  ------------------------------------
  
