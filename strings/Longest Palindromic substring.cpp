https://leetcode.com/problems/longest-palindromic-substring/description/
LEETCODE-5
---------------------------
     BRUTE FORCE
---------------------------
class Solution {
public:
bool isPalindrome(string&s,int left, int right){
    while(left<right){
        if(s[left++]!=s[right--]) return false;
    }
    return true;
}
    string longestPalindrome(string s) {
        int n=s.length();
        int start=0;
        int maxLen=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s,i,j) && j-i+1>maxLen){
                    start=i;
                    maxLen=j-i+1;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
T.C=O(N^3)
S.C=O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------
      Expand Around Center
  -------------------------------------
  class Solution {
public:
    string expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string longest = "";
        for (int i = 0; i < s.length(); i++) {
            // Odd length
            string p1 = expandAroundCenter(s, i, i);
            if (p1.length() > longest.length()) longest = p1;

            // Even length
            string p2 = expandAroundCenter(s, i, i + 1);
            if (p2.length() > longest.length()) longest = p2;
        }
        return longest;
    }
};
T.C=O(N^2)
S.C=O(1)


  
