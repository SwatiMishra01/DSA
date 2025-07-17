https://leetcode.com/problems/asteroid-collision/description/
LEETCODE-735
  class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int>st;

        for(int i=0; i<n; i++){
            //if a +ve element push it
           if(asteroids[i]>0)
                st.push_back(asteroids[i]);
            else{
            //-ve element encountered which explodes small +ve element in st
            while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i])){
                st.pop_back();
            }

                //if same size-> exploode both
                if(!st.empty()&& st.back()==abs(asteroids[i]))
                st.pop_back();
            

              //if st is empty or theres already a -ve element present in st
              // push the -ve element to st
                else if(st.empty() || st.back()<0)
                st.push_back(asteroids[i]);
            }
        }
        return st;
    }
};
T.C=O(2N)
S.C=O(N)
