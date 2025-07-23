https://leetcode.com/problems/median-of-two-sorted-arrays/description/
LEETCODE-4


------------------
  BRUTE FORCE
------------------
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         //size of two given arrays:
    int n1 = nums1.size(), n2 = nums2.size();

    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) arr3.push_back(nums1[i++]);
        else arr3.push_back(nums2[j++]);
    }

    //copy the left-out elements:
    while (i < n1) arr3.push_back(nums1[i++]);
    while (j < n2) arr3.push_back(nums2[j++]);

    //Find the median:
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
    }
};
T.C=O(n1+n2)
S.C=O(n1+n2)


  ---------------------------------------------------------------------------------------------------------------------------------------------------------------

  ---------------------------------------------
   BETTER APPROACH BY KEEPING TRACK OF INDEX
  ---------------------------------------------
  class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //size of two given arrays:
    int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;   //count-to keep track of index
    int ind1el = -1, ind2el = -1; //both elelements

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) {
            //decide elelemnts
            if (cnt == ind1) ind1el = nums1[i];
            if (cnt == ind2) ind2el = nums1[i];
            cnt++;
            i++;
        }
        else { //decide elements
            if (cnt == ind1) ind1el = nums2[j];
            if (cnt == ind2) ind2el = nums2[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = nums1[i];
        if (cnt == ind2) ind2el = nums1[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = nums2[j];
        if (cnt == ind2) ind2el = nums2[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
    }
};
T.C=O(n1+n2)
S.C=O(1)


-------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------
      BINARY SEARCH
  -----------------------
  class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
    //if n1 is bigger swap the arrays:
    //we will work by considering n1 is smallest by default
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

    int n = n1 + n2; //total length
    int left = (n1 + n2 + 1) / 2; //length of left half
    //apply binary search:
    int s = 0, e = n1;
    while (s <= e) {
        int mid1 = (s + e) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN; //as we want max element here
        int r1 = INT_MAX, r2 = INT_MAX; //as we want min elelemnet here
        if (mid1 < n1) r1 = nums1[mid1];
        if (mid2 < n2) r2 = nums2[mid2];
        if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) e = mid1 - 1;
        else s = mid1 + 1;
    }
    return 0; //dummy statement
    }
};
T.C=O(log(min(n1,n2)))
S.C=O(1)
  
