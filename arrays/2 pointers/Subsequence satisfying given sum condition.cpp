1498-  https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/


  APPROACH->
-> aise subsequences count karne hain jinka (min + max) <= target
-> 2pointer ek left,ek right which gives min/max element respectively for given condition
-> Us beech ke elements ka 2^(r-l) subsequence count hota hai.
  
Why Power of 2?
l = 0, r = 2
Elements: [3, 5, 6]

Fix `3` as min aur `6` as max.  
Bech mein `5` hai → wo include ya exclude ho sakta hai → total 2 combinations.
  
---------------------------------------------------------------------------------------------------------------------------
  ALGO-> 
  
✅ Two Pointers Steps
1️⃣ Array ko sort karo:
Example: [3, 5, 6, 7]

2️⃣ Do pointers lo:
l = start (min)
r = end (max)

3️⃣ Jab tak l <= r:
-> Agar nums[l] + nums[r] <= target:
               Valid pair hai!
-> Total subsequences = 2^(r-l) → answer mein add karo
-> l++ (ab next smaller min dekho)
-> (ELSE PART) Agar nums[l] + nums[r] > target:
-> Sum zyada hai, toh r-- karo (max ko chhota karo)

--------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
   
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> pow2(n+1, 1);
    for(int i = 1; i <= n; i++) {
        pow2[i] = (pow2[i-1] * 2) % mod;
    }

    int l = 0, r = n-1, ans = 0;
    while(l <= r) {
        if(nums[l] + nums[r] <= target) {
            ans = (ans + pow2[r - l]) % mod;
            l++;
        } else {
            r--;
        }
    }
    return ans;  
}
};
