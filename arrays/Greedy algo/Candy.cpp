https://leetcode.com/problems/candy/description/
LEETCODE-135
  
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int left[n];
        int right[n];
        left[0]=1;
        right[n-1]=1;
        //for checking from left
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1])
            left[i]=left[i-1]+1;
            else
            left[i]=1;
        }
        //for checking from right
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1])
            right[i]=right[i+1]+1;
            else
            right[i]=1;
        }
        //maximize left and right & sum it up and return
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=max(left[i],right[i]);
        }
        return sum;

        
    }
};
T.C=O(3N)-> 3 for loops
S.C=O(2N)-> 2 arrays built
