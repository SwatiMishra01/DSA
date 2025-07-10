int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
      //finding first element from left which is greater than pivot index
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        //finding first element from right which is smaller than pivot index
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
      //after finding both -> swap
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
      //pivot index
        int pIndex = partition(arr, low, high);
      //left part
        qs(arr, low, pIndex - 1);
      //right part
        qs(arr, pIndex + 1, high);
    }
}
T.C= for the best and average case: O(N*logN)
S.C= O(1) + O(N) auxiliary stack space.
