https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164159?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

--------------
  BRUTE FORCE
  ------------
  int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
   vector<int> arr3;
            
                //apply the merge step:
                int i = 0, j = 0;
                while (i < n && j < m) {
                    if (arr1[i] < arr2[j]) arr3.push_back(arr1[i++]);
                    else arr3.push_back(arr2[j++]);
                }
            
                //copy the left-out elements:
                while (i < n) arr3.push_back(arr1[i++]);
                while (j < m) arr3.push_back(arr2[j++]);
                return arr3[k - 1];
}
T.C=O(m+n)
S.C=O(m+n)
----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------------
  BETTER APPROACH-(Optimized space)
  ------------------------------------
  int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
 int element = -1;
    int cnt = 0; //counter
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (cnt == k - 1) element = arr1[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == k - 1) element = arr2[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n) {
        if (cnt == k - 1) element = arr1[i];
        cnt++;
        i++;
    }
    while (j < m) {
        if (cnt == k - 1) element = arr2[j];
        cnt++;
        j++;
    }
    return element;
}
T.C=O(m+n)
S.C=O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------
  BINARY SEARCH
  ------------------
  int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
 if (n > m) return kthElement(arr2, arr1, m, n, k);

    int left = k; //length of left half

    //apply binary search:
    int s = max(0, k - m), e = min(k, n);
    while (s <= e) {
        int mid1 = (s + e) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN; //as we want maximum
        int r1 = INT_MAX, r2 = INT_MAX; //as we want minimum
        if (mid1 < n) r1 = arr1[mid1];
        if (mid2 < m) r2 = arr2[mid2];
        if (mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = arr2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }

        //eliminate the halves:
        else if (l1 > r2) e = mid1 - 1;
        else s = mid1 + 1;
    }
    return 0; //dummy statement
}
T.C=O(log(min(m, n)))
S.C=O(1)
