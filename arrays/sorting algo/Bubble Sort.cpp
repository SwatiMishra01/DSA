void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                //int temp = arr[j + 1];
                //arr[j + 1] = arr[j];
                //arr[j] = temp;
              swap(arr[j].arr[j+1]);
            }
        }
    }

T.C=O(N^2)  but at best case where array will be already sorted and no swaps needed..it will be O(N)
S.C=O(1)
