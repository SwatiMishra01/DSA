----------------------
  BRUTE FORCE
----------------------
  class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t){
        return true;
        }
        return false;
    }
};
T.C=O(N LOGN)
S.C=O(1)

-----------------------------------------------------------------------------------------------------------------------------------------
  ------------------
     USING MAP
----------------------
  class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>count;
        //s ki freq store kro
       for(auto x:s){
        count[x]++;
       }

     //t ki freq ghatao
       for(auto x:t){
        count[x]--;
       }
   
   //agar 0 hua means same character present tha same baar...if not ->false
   for(auto x:count){
   if(x.second !=0)
   return false;
   }
   return true;

    }
  };

  T.C=O(N)
  S.C=O(1)

  --------------------------------------------------------------------------------------------------------------------------------------------------------------
  
};1
