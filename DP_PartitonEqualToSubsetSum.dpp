https://leetcode.com/problems/partition-equal-subset-sum/description/

-> it is exact same as Subset Sum equal to K
->i have done only memo 
--------------------------------------------------------
            MEMOIZATION
---------------------------------------------------------

int f(int i, int target,vector<int> &arr,vector<vector<int>>&dp){
    // base cases
    if(target==0)
    return true;


    if(i==0)
    return (arr[0]==target);

    //apply memoization
    if(dp[i][target]!=-1)
    return dp[i][target];

    bool not_take= f(i-1,target,arr,dp);
    bool take=false;
    if(target>=arr[i])
    take=f(i-1,target-arr[i],arr,dp);


    return dp[i][target]=(take || not_take);

}


bool canPartition(vector<int> &arr, int n)
{
 int totalSum=0;
 for(int i=0; i<n; i++){
	 totalSum+=arr[i];
 }
	 if(totalSum % 2)
	 return false;
	 

	 int target=totalSum/2;

     vector<vector<int>>dp(n,vector<int>(target+1,-1));
	 return f(n-1,target,arr,dp);

 
 
}
