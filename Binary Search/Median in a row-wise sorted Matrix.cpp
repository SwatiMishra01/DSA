https://www.naukri.com/code360/problems/median-of-a-row-wise-sorted-matrix_1115473?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM
-------------------
BRUTE FORCE
--------------------

int median(vector<vector<int>> &matrix, int m, int n) {
    vector<int> lst;

    //traverse the matrix and
    //copy the elements to list:
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            lst.push_back(matrix[i][j]);
        }
    }

    //sort the list:
    sort(lst.begin(), lst.end());
    return lst[(m * n) / 2];
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------
BINARY SEARCH
----------------------
int countSmallerEqual(vector<int> &row, int x) {
    // upper_bound gives the index of first element greater than x
    return upper_bound(row.begin(), row.end(), x) - row.begin();
}

int median(vector<vector<int>> &matrix, int m, int n) {
     int s = 1;
    int e = 1e9;

    while (s <= e) {
        int mid = (s + e) / 2;
        int count = 0;

        // Count how many numbers are less than or equal to mid
        for (int i = 0; i < m; i++) {
            count += countSmallerEqual(matrix[i], mid);
        }

        if (count <= (m * n) / 2)
            s = mid + 1;
        else
            e = mid - 1;
    }

    return s;
}
