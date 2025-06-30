https://www.naukri.com/code360/problems/rod-cutting-problem_800284

----------------------------------
  APPROACH 1-> RECURSION  (TLE)
-----------------------------------
int f(int indx,int n, vector<int> &price){

	//base cases
	if(indx==0)
	return n*price[0];

	//exploring ass possibilities
	int not_take=0+f(indx-1,n,price);
	int take=INT_MIN; //since it is a max problem
	int rodLength=indx+1;
	if(rodLength<=n)
	take=price[indx]+f(indx,n-rodLength,price);
	


	return max(take,not_take);

}

int cutRod(vector<int> &price, int n)
{
	return f(n-1,n,price);
}

TC: Exponential → O(2^N * N)
  SC: O(N)
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------------------
   APPROACH 2-> MEMOIZATION
  ------------------------------------------------
  int f(int indx,int n, vector<int> &price,vector<vector<int>>&dp){

	//base cases
	if(indx==0)
	return n*price[0];

	//memoization
	if(dp[indx][n]!=-1)
	return dp[indx][n];

	//exploring ass possibilities
	int not_take=0+f(indx-1,n,price,dp);
	int take=INT_MIN; //since it is a max problem
	int rodLength=indx+1;
	if(rodLength<=n)
	take=price[indx]+f(indx,n-rodLength,price,dp);
	


	return dp[indx][n]=  max(take,not_take);

}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
}

TC: O(N * N)
SC: O(N * N)+O(N)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  --------------------------------------------------
    APPROACH 3-> TABULATION
  -------------------------------------------------
  
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n,vector<int>(n+1,0));
	//base cases
	for(int N=0; N<=n; N++){
		dp[0][N]=N*price[0];
	}


	//nested loops
	for(int indx =1; indx<n; indx++){
		for(int N=0; N<=n; N++ ){
			//exploring ass possibilities
	int not_take=0+dp[indx-1][N];
	int take=INT_MIN; //since it is a max problem
	int rodLength=indx+1;
	if(rodLength<=N)
	take=price[indx]+dp[indx][N-rodLength];
	


	 dp[indx][N]=  max(take,not_take);


		}
	}
	return dp[n-1][n];
	
}

TC: O(N * N)
SC: O(N * N)
--------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------------------
   APPROACH 4-> SPACE OPTIMIZATION
  -----------------------------------------
  
int cutRod(vector<int> &price, int n)
{
	 vector<int> prev(n + 1, 0);
	 vector<int> curr(n + 1, 0);
	//base cases
	for(int N=0; N<=n; N++){
		prev[N]=N*price[0];
	}


	//nested loops
	for(int indx =1; indx<n; indx++){
		for(int N=0; N<=n; N++ ){
			//exploring ass possibilities
	int not_take=0+prev[N];
	int take=INT_MIN; //since it is a max problem
	int rodLength=indx+1;
	if(rodLength<=N)
	take=price[indx]+curr[N-rodLength];
	


	 curr[N]=  max(take,not_take);


		}
		prev=curr;
	}
	return prev[n];
	
}

TC: O(N * N)
SC: O(N )
