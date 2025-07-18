https://www.geeksforgeeks.org/problems/rotation4723/1
--------------------------
  BRUTE FORCE
--------------------------
  class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n=arr.size();
        int ans=INT_MAX;
        int index=-1;
        for(int i=0; i<n; i++){
            if(arr[i]<ans){
            ans=arr[i];
            index=i;
            }
        }
        return index;
        
    }
};


----------------------------------------------------------------------------------------------------------------------------------------------------------
  -----------------------------
       BINARY SEARCH
  -----------------------------
  class Solution {
  public:
    int findKRotation(vector<int> &arr) {
      int n=arr.size();
        int s=0; 
        int e=n-1;
        int mini=INT_MAX;
        int index=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            
            //if search space is already sorted
            if(arr[s]<=arr[e]){
                if(arr[s]<mini){
                index=s;
                mini=arr[s];
                }
                break;
            }
            
            
            //if left part is sorted
            if(arr[s]<=arr[mid]){
                   if(arr[s]<mini)
                   mini=arr[s];{
                   index=s;
                   }
                   s=mid+1; //eliminate left half
            }
            //right part is sorted
            else{
                 if(arr[mid]<mini){
                 mini=arr[mid];
                 index=mid;
                 }
                   e=mid-1; //eliminate right half
            }
        }
        return index;
        
    }
};

  
