void insertion_sort(int arr[], int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            // int temp = arr[j - 1];
            // arr[j - 1] = arr[j];
            // arr[j] = temp;
          swap(arr[j-1],arr[j]);
            j--;
        }
    }

T.C=O(N^2)   but at best case where array is sorted-> O(N)
S.C=O(1)
