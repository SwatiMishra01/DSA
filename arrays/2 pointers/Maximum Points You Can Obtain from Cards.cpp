https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
LEETCODE-1423

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=00;
        int rsum=0;
        int maxSum=0;
        for(int i=0; i<k; i++){
         lsum+=cardPoints[i];
         maxSum=lsum;
           }
           int rindx=cardPoints.size()-1;
           for(int i=k-1; i>=0; i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rindx];
            rindx-=1;
            maxSum=max(maxSum,lsum+rsum);
           }
           return maxSum;
           
    }
};

T.C=O(K)
S.C=O(1)
