https://leetcode.com/problems/combination-sum-ii/description/
LEETCODE-40

  class Solution {
    
void backtrack(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int start) {
    //base case
    if (target == 0) {
        result.push_back(current); // Valid combination found
        return;
    }
    if (target < 0) return; // Stop if sum exceeds target

    for (int i = start; i < candidates.size(); i++) {
        // ✅ Missing duplicate skip logic:
        if (i > start && candidates[i] == candidates[i - 1]) continue; // ⚠️ Needed to avoid duplicates
        
        current.push_back(candidates[i]); // Choose the number
        backtrack(candidates, target - candidates[i], current, result, i+1);
        current.pop_back(); // Backtrack
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> result;
    vector<int> current;
    sort(current.begin(),current.end());
    backtrack(candidates, target, current, result, 0);
    return result;
    }
};
TC = O(n log n + 2ⁿ)
SC = O(k + n)
