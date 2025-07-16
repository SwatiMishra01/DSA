https://leetcode.com/problems/next-greater-element-i/description/
LEETCODE-496

  -------------------------------
  APPROACH 1-> BRUTE FORCE
---------------------------------
  class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>res(n,-1);

        for(int i=0; i<n; i++){
            bool found=false;
            for(int j=0; j<m; j++){
          if(nums1[i]==nums2[j])
          found=true;

          if(found && nums2[j]>nums1[i]){
          res[i]=nums2[j];
          break;
          }
         }
        }
        return res;
    }
};
T.C=O(N^2)
S.C=O(N)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------
  APPROACH 2-> MONOTONIC STACK
  -----------------------------------
  class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge; // num → next greater element
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[nums2[i]] = st.top();
            } else {
                nge[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }

        vector<int> res;
        for (int num : nums1) {
            res.push_back(nge[num]);
        }

        return res;
    }
};
T.C=O(N)
S.C=O(N) (map + stack)
