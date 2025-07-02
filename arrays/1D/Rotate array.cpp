https://leetcode.com/problems/rotate-array/
189-leetcode
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if (n <= 1) return; 
        k=k%n; // If k > n, rotate only necessary times
        for(int i=0; i<k; i++){  // Repeat k times
            int last=nums[n-1];  // Store last element

            for(int j=n-1; j>0; j--){
                nums[j]=nums[j-1];    // Shift all right by 1
            }
            //last vaale ko shuru mein daaldo
            nums[0]=last;   // Insert last element at front
        }
    }
};
Time: O(N × k) → Each rotation is O(N), done k times.
Space: O(1) → Uses only one temp variable last.
    --------------------------------------------------------------------------------
-------------------------------
    Reversal Algorithm
------------------------------
⚡ Reversal Algorithm for Right Rotation
->Reverse the whole array
->Reverse the first k elements
->Reverse the rest (n − k elements)

🗂️ Dry Run for Optimal
Original: [1, 2, 3, 4, 5, 6, 7]
1️⃣ Reverse all → [7, 6, 5, 4, 3, 2, 1]
2️⃣ Reverse first 3 → [5, 6, 7, 4, 3, 2, 1]
3️⃣ Reverse last 4 → [5, 6, 7, 1, 2, 3, 4] ✅



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if (n <= 1) return;
        k=k%n;
        //reverse whole array
        reverse(nums.begin(),nums.end());
        //reverse till first k
        reverse(nums.begin(),nums.begin()+k);
        //reverse remaining n-k
        reverse(nums.begin()+k, nums.end());
    }
};
T.C= O(N)
S.C=O(1)
