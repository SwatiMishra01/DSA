https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n=arr.size();
        vector<int> NGE(n, -1);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(!st.empty())
        NGE[i]=st.top();
        
        st.push(arr[i]);
            
        }
        return NGE;
    }
};
T.C=O(N)
S.C=O(N)
