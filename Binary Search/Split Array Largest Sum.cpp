https://leetcode.com/problems/split-array-largest-sum/description/
LEETCODE-410

------------------
BRUTE FORCE-TLE
-----------------
class Solution {
public:
int countPartitions(vector<int> &nums, int maxSum) {
    int n = nums.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + nums[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += nums[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = nums[i];
        }
    }
    return partitions;
}

    int splitArray(vector<int>& nums, int k) {
         int s = *max_element(nums.begin(), nums.end());  //max
    int e = accumulate(nums.begin(), nums.end(), 0);  //sum of all elements
    for (int maxSum = s; maxSum <= e; maxSum++) {
        if (countPartitions(nums, maxSum) == k)
            return maxSum;
    }
    return s;
    }
};
T.C= O(N * (sum(arr[])-max(arr[])+1))
S.C=O(1)



----------------------------------------------------------------------------------------------------------------------------------------------------------------


---------------------------------
   BINARY SEARCH
--------------------------------

class Solution {
public:
int countPartitions(vector<int> &nums, int maxSum) {
    int n = nums.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + nums[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += nums[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = nums[i];
        }
    }
    return partitions;
}

    int splitArray(vector<int>& nums, int k) {
         int s = *max_element(nums.begin(), nums.end());  //max
    int e = accumulate(nums.begin(), nums.end(), 0);  //sum of all elements
    //Apply binary search:
    while (s <= e) {
        int mid = (s + e) / 2;
        int partitions = countPartitions(nums, mid);
        if (partitions > k) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return s;
    }
};
T.C= O(N * log(sum(arr[])-max(arr[])+1))
S.C=O(1)
