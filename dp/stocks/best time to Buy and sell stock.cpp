https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
leetcode-121


class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
    int mini=prices[0];
    int profit=0;
    for(int i=0; i<n; i++){
        int cost=prices[i]-mini;
        profit=max(cost,profit);
        mini=min(mini,prices[i]);
    }
    return profit;
    }
};

T.C=O(N);
S.C=O(1);
