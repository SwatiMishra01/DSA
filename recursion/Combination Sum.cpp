https://leetcode.com/problems/combination-sum/description/
LEETCODE-39
class Solution {
    
void backtrack(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int start) {
    //base case
    if (target == 0) {
        result.push_back(current); // Valid combination found
        return;
    }
    if (target < 0) return; // Stop if sum exceeds target

    for (int i = start; i < candidates.size(); i++) {
        current.push_back(candidates[i]); // Choose the number
        backtrack(candidates, target - candidates[i], current, result, i); // Allow repetition
        current.pop_back(); // Backtrack
    }
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> result;
    vector<int> current;
    backtrack(candidates, target, current, result, 0);
    return result;
    }
};
