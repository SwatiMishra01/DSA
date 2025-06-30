https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
LEETCODE-1752
-------------------
  COUNT THE DROPS
  -------------------
  int count = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i+1)%n])
            count++;
    }
    return count <= 1;
TC: O(n) — single pass
SC: O(1)


  
