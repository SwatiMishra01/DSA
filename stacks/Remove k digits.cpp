https://leetcode.com/problems/remove-k-digits/description/
LEETCODE-402

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        //comparing elements and removing if greater
        for(int i=0; i<num.size(); i++){
        while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
            st.pop();
            k--;
        }
            st.push(num[i]);
        }
      //removing left out k digits from top
        while(k>0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        //storing stack elements in res
         string res = "";
        while(!st.empty()){
            res+=(st.top());
            st.pop();
        }

        //edge case to trim trailing zeros
        while(res.size()!=0 && res.back()=='0') {
             res.pop_back();
        }

        //reverse the res
        reverse(res.begin(),res.end());

        if(res.empty())  return "0";
        return res;


    }
};
T.C=O(N)
S.C=O(N)
