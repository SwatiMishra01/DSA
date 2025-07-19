https://leetcode.com/problems/single-element-in-a-sorted-array/description/
LEETCODE- 540
---------------------------
    BRUTE FORCE
--------------------------
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        //base case
        if(n==1) return nums[0];

        for(int i=0; i<n; i++){
         //check for first index
         if(i==0){
            if(nums[i]!=nums[i+1]) return nums[i];
         }
         //check for last index
         else if(i==n-1){
         if(nums[i]!=nums[i-1])   return nums[i];
         }
         //check for middle elements

         else {
           if( nums[i]!=nums[i+1]  && nums[i]!=nums[i-1])
           return nums[i];
            }
        }
        return -1;
    }
};
T.C=O(N)
S.C=O(1)
-----------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------
           USING XOR
  --------------------------------------
  class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) { 
        //USING XOR
       // a ^ a = 0, XOR of two same numbers results in 0.
       // a ^ 0 = a, XOR of a number with 0 always results in that number.
       int n=nums.size();
       int ans=0;
       for(int i=0; i<n; i++){
        ans=ans^nums[i];
       }
       return ans;
        
    }
};
T.C=O(N)
S.C=O(1)

------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------
          BINARY SEARCH
  --------------------------------------
  class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        //3 edge cases
        if(n==1) return nums[0]; //if there is only 1 element in array
        if(nums[0]!=nums[1])  return nums[0]; // if first element is unique
        if(nums[n-1]!=nums[n-2]) return nums[n-1]; //if last element is unique

        int s=0; int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])   return nums[mid];
            if(   (mid%2==1 && nums[mid]==nums[mid-1]) || 
                  (mid%2==0 && nums[mid]==nums[mid+1] )  )
            //eliminate left half
            s=mid+1;
            else 
            //eliminate right half
            e=mid-1;
        }
        return -1;

        
    }
};



// int singleNonDuplicate(vector<int>& arr) {
//     int n = arr.size(); //size of the array.

//     //Edge cases:
//     if (n == 1) return arr[0];
//     if (arr[0] != arr[1]) return arr[0];
//     if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

//     int low = 1, high = n - 2;
//     while (low <= high) {
//         int mid = (low + high) / 2;

//         //if arr[mid] is the single element:
//         if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
//             return arr[mid];
//         }

//         //we are in the left:
//         if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
//                 || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
//             //eliminate the left half:
//             low = mid + 1;
//         }
//         //we are in the right:
//         else {
//             //eliminate the right half:
//             high = mid - 1;
//         }
//     }

//     // dummy return statement:
//     return -1;
// }
