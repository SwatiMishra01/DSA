https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

  class Solution {
  public:
    int longestKSubstr(string &s, int k) {
       if (k == 0) return 0;
    unordered_map<char,int> cnt;
    int left = 0, best = 0;
    for (int right = 0; right < (int)s.size(); ++right) {
        cnt[s[right]]++;
        while ((int)cnt.size() > k) {
            if (--cnt[s[left]] == 0) cnt.erase(s[left]);
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
        
    }
};
