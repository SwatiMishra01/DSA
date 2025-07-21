https://www.geeksforgeeks.org/problems/aggressive-cows/1

( MAX OF MIN)  -> MAX(MIN) PROBLEM
-----------------------
  BRUTE FORCE
  ---------------------
  // User function Template for C++

class Solution {
  public:
  
  bool canWePlace(vector<int> &stalls,int dist,int cows){
      int countCows=1;
      int lastposition=stalls[0];
      for(int i=0; i<stalls.size(); i++){
          if((stalls[i]-lastposition)>=dist)
          {
              countCows++; //place one more cow
              lastposition=stalls[i];//update last position of cow
              
          }
          if(countCows>=cows) return true;
      }
       return false;
  }

    int aggressiveCows(vector<int> &stalls, int k) {
        int n=stalls.size();
        //sort the stalls
        sort(stalls.begin(),stalls.end());

//max dist where two cows can we placed are at first and last position
     for(int i=1; i<(stalls[n-1]-stalls[0]); i++){
         if(canWePlace(stalls,i,k)==false)
         return (i-1); //prev place where cow was placed
     }
     return (stalls[n - 1] - stalls[0]); //else return max dist b/w 2cows
        
    }
};
T.C=O(NlogN) + O(N *(max(stalls[])-min(stalls[])))
S.C=O(1)

---------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------
     BINARY SEARCH
  -----------------------
  // User function Template for C++

class Solution {
  public:
  
  bool canWePlace(vector<int> &stalls,int dist,int cows){
      int countCows=1;
      int lastposition=stalls[0];
      for(int i=0; i<stalls.size(); i++){
          if((stalls[i]-lastposition)>=dist)
          {
              countCows++; //place one more cow
              lastposition=stalls[i];//update last position of cow
              
          }
          if(countCows>=cows) return true;
      }
       return false;
  }

    int aggressiveCows(vector<int> &stalls, int k) {
        int n=stalls.size();
        //sort the stalls
        sort(stalls.begin(),stalls.end());
        int s=1;
        int e=stalls[n-1]-stalls[0];
        while(s<=e){
            int mid=s+(e-s)/2;
            if(canWePlace(stalls,mid,k)==true)  s=mid+1; 
            else e=mid-1;
        }
        return e;  //it will be opposite -> s=not possible ans
                   //                     -> e= possible ans
        
    }
};
  
