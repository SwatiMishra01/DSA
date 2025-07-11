class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, int>> ratio(n); // {ratio, index}

        for (int i = 0; i < n; i++) {
            ratio[i] = { (double)val[i] / wt[i], i };
        }

        sort(ratio.rbegin(), ratio.rend()); // sort in decreasing order

        double totalValue = 0.0;

        for (int i = 0; i < n; i++) {
            int idx = ratio[i].second;
            if (wt[idx] <= capacity) {
                capacity -= wt[idx];
                totalValue += val[idx];
            } else {
                totalValue += val[idx] * ((double)capacity / wt[idx]);
                break;
            }
        }

        return totalValue;
    }
};
TC=O(n)+O(nlogn)+O(n)=  O(nlogn)
SC=O(n)
