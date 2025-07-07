https://leetcode.com/problems/fruit-into-baskets/description/
LEETCODE-904

  ---------------------
    BRUTE FORCE  (TLE)
  ----------------------
  class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxLen=0;
        int n=fruits.size();
        for(int i=0; i<n; i++){
            set<int>st;
            for(int j=i; j<n; j++){
                st.insert(fruits[j]);
                if(st.size()<=2)
                maxLen=max(maxLen,j-i+1);
                else
                break;
            }
        }
        return maxLen;
    }
};

T.C=O(N^2)
S.C=O(3)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------
    SLIDING WINDOW
  -------------------------------
  unordered_map<int, int> basket;
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < fruits.size()) {
            basket[fruits[right]]++;

            // If more than 2 types, shrink window
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
T.C=O(N)
S.C=O(N)
  
