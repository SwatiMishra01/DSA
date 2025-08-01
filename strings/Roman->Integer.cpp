https://leetcode.com/problems/roman-to-integer/description/
LEETCODE- 13
----------------------------
       BRUTE FORCE
----------------------------
  class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'I' && i + 1 < n && (s[i+1] == 'V' || s[i+1] == 'X')) {
                ans += (s[i+1] == 'V') ? 4 : 9;
                i++;
            }
            else if(s[i] == 'X' && i + 1 < n && (s[i+1] == 'L' || s[i+1] == 'C')) {
                ans += (s[i+1] == 'L') ? 40 : 90;
                i++;
            }
            else if(s[i] == 'C' && i + 1 < n && (s[i+1] == 'D' || s[i+1] == 'M')) {
                ans += (s[i+1] == 'D') ? 400 : 900;
                i++;
            }
            else {
                if(s[i] == 'I') ans += 1;
                else if(s[i] == 'V') ans += 5;
                else if(s[i] == 'X') ans += 10;
                else if(s[i] == 'L') ans += 50;
                else if(s[i] == 'C') ans += 100;
                else if(s[i] == 'D') ans += 500;
                else if(s[i] == 'M') ans += 1000;
            }
        }
        return ans;
    }
};
T.C=O(N)
S.C=O(1)
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------
          USING MAP
  ------------------------------------
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int n = s.length();
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            if(i + 1 < n && mp[s[i]] < mp[s[i+1]]) {
                ans += mp[s[i+1]] - mp[s[i]];
                i++; // skip next character
            }
            else {
                ans += mp[s[i]];
            }
        }
        return ans;
    }
};
T.C=O(N)
S.C=O(1)



  
