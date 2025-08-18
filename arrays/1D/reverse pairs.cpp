https://leetcode.com/problems/reverse-pairs/description/
LEETCODE-493
---------------------
  BRUTE FORCE-TLE
---------------------
  class Solution {
public:
    int reversePairs(vector<int>& nums) {
      int count=0;
      int n=nums.size();
        for(int i=0; i<n; i++){
          for(int j=i+1; j<n; j++){
            if((long long)nums[i]>2LL*nums[j]) count++;
          }
        }
        return count;
    }
};
T.C=O(N^2)
S.C=O(1)

  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------
    USING MERGESORT
  ---------------------------
  class Solution {
  private:
  void merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

int countPairs(vector<int> &nums, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && (long long)nums[i] > 2LL * nums[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &nums, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(nums, low, mid);  // left half
    cnt += mergeSort(nums, mid + 1, high); // right half
    cnt += countPairs(nums, low, mid, high); //Modification
    merge(nums, low, mid, high);  // merging sorted halves
    return cnt;
}
public:
    int reversePairs(vector<int>& nums) {
      int n=nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};
