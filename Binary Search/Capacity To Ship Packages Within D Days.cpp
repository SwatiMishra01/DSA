https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
LEETCODE-1011

---------------------------
 BRUTE FORCE
----------------------------
  int findDays(vector<int> &weights, int cap) {
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d) {
    //Find the maximum and the summation:
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

    for (int i = maxi; i <= sum; i++) {
        if (findDays(weights, i) <= d) {
            return i;
        }
    }
    //dummy return statement:
    return -1;
}
T.C=O(N * (sum(weights[]) - max(weights[]) + 1))
S.C=O(1)
---------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------
  BINARY SEARCH
---------------------
class Solution {
public:
 int findDays(vector<int>& weights,int capacity){
    int days=1;
    int load=0;
    for(int i=0; i<weights.size(); i++){
        if (load + weights[i] > capacity) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else //load the weight on the same day.
            load += weights[i];
    }
    return days;
 }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(int i=0; i<weights.size(); i++){
            sum+=weights[i];
        }
        int s=maxi;
        int e=sum;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(findDays(weights,mid)<=days) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};
T.C=(N * log(sum(weights[]) - max(weights[]) + 1))
S.C=O(1)
