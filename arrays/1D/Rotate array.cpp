https://leetcode.com/problems/rotate-array/
189-leetcode
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if (n <= 1) return;
        k=k%n;
        for(int i=0; i<k; i++){
            int last=nums[n-1];

            for(int j=n-1; j>0; j--){
                nums[j]=nums[j-1];
            }
            //last vaale ko shuru mein daaldo
            nums[0]=last;
        }
    }
};
