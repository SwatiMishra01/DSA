https://www.naukri.com/code360/problems/previous-smaller-element_1112581
------------------------------------------------
  APPROACH 1-> BRUTE FORCE- using 2 for loops
--------------------------------------------------
  vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>res(n,-1);
   for(int i=0; i<n;i++){
       for(int j=i+1; j<n; j++){
           if(arr[j]<arr[i]){
           res[i]=arr[j];
           break;
        }
     }
   }
   return res;
}
T.C=O(N^2)
S.C=O(N)

---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------------------------------------------
   APPROACH 2-> MONOTONIC STACK
  ---------------------------------------------------------------------------
  #include <vector>
#include <stack>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        // Remove all greater/equal elements
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // If stack is not empty, the top is the next smaller element
        if (!st.empty()) {
            res[i] = st.top();
        }

        // Push current element for next comparisons
        st.push(arr[i]);
    }

    return res;
}

T.C=O(N)
S.C=O(N)
