https://leetcode.com/problems/integer-to-roman/
LEETCODE-12

  ---------------------------
    BRUTE FORCE
  ---------------------------
  class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
            {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
            {1,    "I"}
        };

        string res = "";
        for (auto &[val, sym] : roman) {
            while (num >= val) {
                res += sym;
                num -= val;
            }
        }
        return res;
    }
};
T.C=O(1)
S.C=O(1)
