https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/description/
LEETCODE-1013 (EASY)
  class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n=arr.size();
        int totalSum=0;
        //if total sum  is not divisible by 3 it cant be divided into 3 parts with equal sum
        for(int i=0;i<n; i++){
            totalSum+=arr[i];
        }
        //base case ->
        if(totalSum%3!=0)
        return false;




        int target=totalSum/3;
        int prefixSum=0;
        int count=0;

        for(int i=0; i<n; i++){
            prefixSum+=arr[i];
            if(prefixSum==target){
            count++;
            prefixSum=0;// Start new subarray
            }
        }


        if(count>=3)
        return true;

       return false;
    }
};

T.C=O(2N)
S.C=O(1)
