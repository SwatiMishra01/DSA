link- # https://leetcode.com/problems/zero-array-transformation-iii/?envType=daily-question&envId=2025-05-22
--------------------------------------------------------------------------------------------------------------
Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]

Output: 1

Explanation:

After removing queries[2], nums can still be converted to a zero array.

Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.

-----------------------------------------------------------------------------------------------------------------
APPROACH

Key Observation:
- Har index i par tumhe nums[i] times decrement karna hoga.
- Tum check karo ki kitni queries index i ko cover karti hain.
- Agar kisi index i ko cover karne wali queries nums[i] se kam hain, to kabhi bhi usse 0 nahi bana paoge → answer -1.

 Strategy:
- Initially maan lo sari queries use kar rahe ho.
- Har index i pe cover[i] count karo (kitni queries usse touch karti hain).
- Ab check karo:
- cover[i] >= nums[i] hona chahiye for all i

Try removing each query one by one, and check:
Agar us query ko hataane ke baad bhi cover[i] >= nums[i] for all i ho, to us query ko hata sakte ho.

------------------------------------------------------------------------------------------------------------------
✅ Dry Run:
nums = [2, 0, 2]
queries = [[0,2], [0,2], [1,1]]

--> Step 1: Count cover for each index
Query [0,2]: index 0,1,2 → +1
Query [0,2]: index 0,1,2 → +1
Query [1,1]: index 1 → +1

Resulting cover array: [2, 3, 2]

-->Step 2: Check if cover[i] >= nums[i]?
Yes: 2≥2, 3≥0, 2≥2 ⇒ zero array ban sakta hai

-->Step 3: Try removing query [1,1]
New cover: [2, 2, 2]
Check again: 2≥2, 2≥0, 2≥2 ⇒ still OK ✅

Answer = 1 (you can remove one query)
--------------------------------------------------------------------------------------------------------------------
class Solution {
public:
bool canMakeZeroArray(vector<int>& nums, vector<vector<int>>& queries, vector<bool>& used) {
    int n = nums.size();
    vector<int> cover(n, 0);

    for (int i = 0; i < queries.size(); ++i) {
        if (used[i]) {
            int l = queries[i][0], r = queries[i][1];
            for (int j = l; j <= r; ++j) {
                cover[j]++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (cover[i] < nums[i])
            return false;
    }
    return true;
}




    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
         int q = queries.size();
    vector<bool> used(q, true);

    // Try removing each query
    int removable = 0;
    for (int i = 0; i < q; ++i) {
        used[i] = false;

        if (canMakeZeroArray(nums, queries, used)) {
            removable++; // query i can be removed
        } else {
            used[i] = true; // keep this query
        }
    }

    // Final check: if after keeping necessary queries, we still can't make zero array
    if (!canMakeZeroArray(nums, queries, used)) return -1;

    return removable;
    }
};


