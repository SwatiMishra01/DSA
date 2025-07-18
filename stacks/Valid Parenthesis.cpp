https://leetcode.com/problems/valid-parentheses/description/
LEETCODE-20

class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(auto it :s){
            if(it =='(' || it=='[' || it=='{'){
                st.push(it);
            }
            else{
                if(st.size()==0)   return false;

                char ch=st.top();
                st.pop();
                if(    (it==')' && ch=='(')  ||
                       (it==']'&& ch=='[')   ||
                       (it=='}' && ch=='{')
                )
                continue;
                else return false;
                
            }
        }
        return st.empty();
    }
};
T.C=O(N)
S.C=O(N)
