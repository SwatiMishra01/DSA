https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1
class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
     int n=arr.size();
     vector<int>res(n,-1);
     stack<int>st;
     for(int i=0; i<n; i++){
         while(!st.empty() && st.top()>=arr[i]){
             st.pop();
         }
         
         if(!st.empty())
         res[i]=st.top();
         
         st.push(arr[i]);
     }
     return res;
        
    }
};
T.C=O(2N)
S.C=O(N)
