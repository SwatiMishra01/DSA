Pre-requisite: Lower Bound implementation, Upper Bound implementation, & Find the first occurrence of a number.

ARR[][]=  0 0 1 1 1   o/p->2
          0 0 0 0 0
          0 1 1 1 1
          0 1 1 1 1  

  EXPLANATION-> 0 0 1 1 1   0th row-> three 1's
                0 0 0 0 0   1st row-> zero 1's
                0 1 1 1 1   2nd row-> four 1's
                0 1 1 1 1   3rd row-> four 1's
-------------------
  BRUTE FORCE
-------------------
  int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        int cnt_ones = 0;
        for (int j = 0; j < m; j++) {
            cnt_ones += matrix[i][j];
        }
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
T.C=O(n X m)
S.C=O(1)


  -----------------------------------------------------------------------------------------------------------------------
  -------------------
   BINARY SEARCH
  -------------------
  int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
T.C=O(n X logm)
S.C=O(1)
  
