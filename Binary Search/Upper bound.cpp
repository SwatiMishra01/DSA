-------------------------
     BRUTE FORCE
--------------------------
int upperBound(vector<int> &arr, int x, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) {
            // upper bound found:
            return i;
        }
    }
    return n;
}
T.C=O(N)
S.C=O(1)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------
  BINARY SEARCH
  ---------------------
  int upperBound(vector<int> &arr, int x, int n) {
    int s = 0, e = n - 1;
    int ans = n;

    while (s <= e) {
        int mid = (s + e) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            e = mid - 1;
        }
        else {
            s = mid + 1; // look on the right
        }
    }
    return ans;
}
T.C=O(N LOG N)
S.C=O(1)
