https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/
LEETCODE-1574

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int r=arr.size()-1;
       while(r>0 && arr[r]>=arr[r-1]){
        r--;
       }
       int ans=r;
       int l=0;
       while(l<r && ( l==0 || arr[l-1]<=arr[l])){ 
        //finding next valid after arr[l]
        while(r<arr.size() && arr[l]>arr[r]){
            r++;
        }
        ans=min(ans,r-l-1);
        l++;
       }
       return ans;
    }
};
