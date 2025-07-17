https://leetcode.com/problems/sum-of-subarray-ranges/description/
LEETCODE-2104

---------------------------------
   APPROACH 1-> BRUTE FORCE
---------------------------------
  class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            int largest=nums[i];
            int smallest=nums[i];
                   for(int j=i+1; j<nums.size(); j++){
                    largest=max(largest,nums[j]);
                    smallest=min(smallest,nums[j]);

                    sum+=(largest-smallest);
                   }
        }
        return sum;
    }
};
T.C=O(N^2)
S.C=O(1)

-------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------
   APPROACH 2-> 
----------------------------------------
  
  class Solution {
public:
    // --------- SUM OF SUBARRAY MAXIMUM FUNCTION -----------------------
    long long sumSubarrayMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Greater or Equal
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                count += left[st.top()];
                st.pop();
            }
            left[i] = count;
            st.push(i);
        }

        st = stack<int>(); // reset stack

        // Next Greater
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!st.empty() && nums[i] > nums[st.top()]) {
                count += right[st.top()];
                st.pop();
            }
            right[i] = count;
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i)
            sum += 1LL * nums[i] * left[i] * right[i];

        return sum;
    }

    // --------- SUM OF SUBARRAY MINIMUM FUNCTION ---------------------
    long long sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Less
        for (int i = 0; i < n; ++i) {
            int count = 1;
            while (!st.empty() && nums[i] < nums[st.top()]) {
                count += left[st.top()];
                st.pop();
            }
            left[i] = count;
            st.push(i);
        }

        st = stack<int>(); // reset stack

        // Next Less or Equal
        for (int i = n - 1; i >= 0; --i) {
            int count = 1;
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                count += right[st.top()];
                st.pop();
            }
            right[i] = count;
            st.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; ++i)
            sum += 1LL * nums[i] * left[i] * right[i];

        return sum;
    }

    // --------- MAIN FUNCTION ---------------------
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};
T.C=O(5N)+O(5N)=O(10N) ~ O(N)
S.C=O(N)
  
