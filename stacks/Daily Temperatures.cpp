https://leetcode.com/problems/daily-temperatures/
LEETCODE-739

  ----------------------
    BRUTE FORCE
  ----------------------
  class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>result(n,0);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(temperatures[i]<temperatures[j]){
                result[i]=j-i;
                break;
                }
            }
        }
        return result;
    }
};
T.C=O(N^2)
S.C=O(N)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------
     USING STACKS
  ---------------------
  class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>result(n,0);
        stack<int>st;

        for(int i=0; i<n; i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int prev_indx=st.top();
                st.pop();
                result[prev_indx]=i-prev_indx;
            }
            st.push(i);
        }
        return result;
    }
};
T.C=O(N)
S.C=O(N)
