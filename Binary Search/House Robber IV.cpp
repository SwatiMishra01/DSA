https://leetcode.com/problems/house-robber-iv/description/
LEETCODE-2560
  
class Solution {
public:
    bool canRob(vector<int>& nums, int k, int cap) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n;) {
            if (nums[i] <= cap) {
                count++;
                i += 2; // skip next house
            } else {
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int s = *min_element(nums.begin(), nums.end());
        int e = *max_element(nums.begin(), nums.end());
        int ans = e;
        
        while (s <= e) {
            int mid = s + (e - s)/2;
            if (canRob(nums, k, mid)) {
                ans = mid;
                e = mid - 1; // try smaller capability
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
T.C=O(n⋅log(max(nums)−min(nums)))
S.C=O(1)
