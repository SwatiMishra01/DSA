https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
LEETCODE-1482

  ---------------------------
    BRUTE FORCE-TLE
  --------------------------
  class Solution {
public:
bool isPossible(vector<int>& bloomDay,int day, int m, int k){
    int count=0;
    int totalBouquets=0;
    for(int i=0; i<bloomDay.size(); i++){
        if(bloomDay[i]<=day)
        count++;
        else{
        totalBouquets+=count/k;
        count=0; //resent count to 0
        }
    }
    totalBouquets += (count / k);
    return totalBouquets >= m;
}


    int minDays(vector<int>& bloomDay, int m, int k) {
        //base case
        int n=bloomDay.size();
        if((m*k)>n)  return -1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0; i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        for(int i=mini;i<=maxi; i++){
          if(isPossible(bloomDay,i,m,k))
          return i;
        }
        return -1;
    }
};

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------
    BINARY SEARCH
  ----------------------------
  class Solution {
public:
bool isPossible(vector<int>& bloomDay,int day, int m, int k){
    int count=0;
    int totalBouquets=0;
    for(int i=0; i<bloomDay.size(); i++){
        if(bloomDay[i]<=day)
        count++;
        else{
        totalBouquets+=count/k;
        count=0; //resent count to 0
        }
    }
    totalBouquets += (count / k);
    return totalBouquets >= m;
}


    int minDays(vector<int>& bloomDay, int m, int k) {
        //base case
        int n=bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if(val>n)  return -1;
        int s=INT_MAX;
        int e=INT_MIN;
        for(int i=0; i<n;i++){
            s=min(s,bloomDay[i]);
            e=max(e,bloomDay[i]);
        }

        while(s<=e){
            int mid=s+(e-s)/2;
          if(isPossible(bloomDay,mid,m,k))
          e=mid-1;
          else  s=mid+1;
        }
        return s;
    }
};
