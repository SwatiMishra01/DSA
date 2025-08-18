https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
-----------------------------
   BRUTE FORCE
-----------------------------
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int n=arr.size();
       int repeating=-1;
       int missing=-1;
      
      for(int i=1; i<=n; i++){
          int count=0;
          for(int j=0; j<n; j++){
              if(arr[j]==i)count++;
          }
          if(count==2) repeating=i;
          else if(count==0) missing=i;
          
          if(repeating!=-1 && missing!=-1) break;
      }
      return {repeating,missing};
        
    }
};
T.C=O(N^2)
S.C=O(1)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------
       USING   HASHMAP
  ------------------------------
  class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size();
        vector<int>hash(n+1,0);
        for(int i=0; i<n; i++){
            hash[arr[i]]++;
            
        }
        
        int repeating=-1;
        int missing=-1;
        
        for(int i=1; i<=n; i++){
            if(hash[i]==2) repeating=i;
            else if(hash[i]==0) missing=i;
            
            if(repeating!=-1 && missing!=-1) break;
        }
        
     return {repeating,missing};
        
    }
};
T.C=O(2N)
S.C=O(N)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------
       USING MATHS
  -------------------------
  class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6; //square

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
    }
};
T.C=O(N)
S.C=O(1)
