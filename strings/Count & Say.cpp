https://leetcode.com/problems/count-and-say/
LEETCODE-38
  ---------------------------
  BRUTE FORCE(RECURSIVE)
  ----------------------------
class Solution {
public:
string say(string s) {
    string res = "";
    int count = 1;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1])  count++;
         else {
            res += to_string(count) + s[i-1];
            count = 1;
        }
    }
    res += to_string(count) + s.back();
    return res;
}
    string countAndSay(int n) {
        if (n == 1) return "1";
    return say(countAndSay(n - 1));
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------
  BRUTE FROCE(ITERATIVE)
  ---------------------------
  class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

    for (int i = 2; i <= n; i++) {
        string temp = "";
        int count = 1;
        for (int j = 1; j < result.length(); j++) {
            if (result[j] == result[j - 1]) {
                count++;
            } else {
                temp += to_string(count) + result[j - 1];
                count = 1;
            }
        }
        temp += to_string(count) + result.back(); // last group
        result = temp;
    }

    return result;
    }
};
