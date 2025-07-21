https://leetcode.com/problems/kth-missing-positive-number/description/
LEETCODE-1539

------------------------
  BRUTE FORCE
-----------------------
  class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<=k) k++;
            else break;
        }
        return k;
        
    }
};
T.C=O(N);
S.C=O(1);

---------------------------------------------------------------------
  ----------------------------
         BINARY SEARCH
  -----------------------------
  class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
         int s = 0, e = n - 1;
    while (s <= e) {
        int mid = (s + e) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return k + e + 1;
    }
};
T.C=O(logN)
S.C=O(1)
  
