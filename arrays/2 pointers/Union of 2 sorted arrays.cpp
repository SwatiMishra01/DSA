https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
----------------------------
  USING SET
------------------------
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n=a.size();
        int m=b.size();
      set<int>s;
      vector<int>ans;
      for(int i=0; i<n; i++){
          s.insert(a[i]);
      }
      for(int i=0; i<m; i++){
          s.insert(b[i]);
      }
      
      for(auto &it:s){
          ans.push_back(it);
      }
      return ans;
    }
};
T.C=O((m+n)log(m+n))
S.C=O(m+n)
  ------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------
  USING Two Pointers
------------------------
1️⃣ Use two pointers:
i → points to arr1
j → points to arr2

2️⃣ Compare arr1[i] and arr2[j]:
If arr1[i] < arr2[j]: pick arr1[i] and move i.
If arr2[j] < arr1[i]: pick arr2[j] and move j.
If equal: pick any, move both.

3️⃣ Always check Union.back() != current to avoid duplicates.

4️⃣ After the main loop, there may be leftover elements in one array — add those too (without duplicates).





class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n=a.size();
        int m=b.size();
      vector<int>unionArr;
      //2 pointers
      int i=0; 
      int j=0;
      
      while(i<n && j<m){
          if(a[i]<=b[j]){
          if(unionArr.size()==0 || unionArr.back()!=a[i])
          unionArr.push_back(a[i]);
          i++;
          }
          else{
              if(unionArr.size()==0 || unionArr.back()!=b[j])
              unionArr.push_back(b[j]);
              j++;
          }
      }
      
      //if there is remaining elements in arr1
      while(i<n){
          if( unionArr.back()!=a[i])
          unionArr.push_back(a[i]);
          i++;
      }
      
      //if there is remaining elemts in array2
      while(j<m){
          if( unionArr.back()!=b[j])
              unionArr.push_back(b[j]);
              j++;
      }
      
      return unionArr;
      
    }
};
T.C=O(m+n)
S.C=O(m+n)
