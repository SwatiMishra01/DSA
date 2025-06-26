
https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM

----------------------------------
    APPROACH 1-> RECURSION  (TLE)
---------------------------------
  int f(int day, int last,vector<vector<int>> &points){
    if(day==0){
    int maxi=0;
    for(int task=0; task<3; task++){
        if(task!=last)
        maxi=max(maxi,points[0][task]);
    }
    return maxi;
    }

    int maxi=0;
    for(int task=0; task<3; task++){
        if(task!=last){
        int point=points[day][task]+ f(day-1,task,points);
        maxi=max(point,maxi);
        }
    }
    return maxi;

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
   return f(n-1,3,points);
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  -------------------------------------------------------------------------------------------
     APPROACH 2-> MEMOIZATION   (TLE)-because of constraints N<=10^5...as it works till 10^3
  -------------------------------------------------------------------------------------------



T.C=O(N*4)*3
S.C=O(N)+O(N*4)


  int f(int day, int last,vector<vector<int>> &points,vector<vector<int>>dp){
    if(day==0){
    int maxi=0;
    for(int task=0; task<3; task++){
        if(task!=last)
        maxi=max(maxi,points[0][task]);                     
    }
    return maxi;
    }

if(dp[day][last]!=-1)
return dp[day][last];


    int maxi=0;
    for(int task=0; task<3; task++){
        if(task!=last){
        int point=points[day][task]+ f(day-1,task,points,dp);
       maxi=max(point,maxi);
        }
    }
    return dp[day][last]=maxi;

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
   return f(n-1,3,points,dp);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------------------------------
                 APPROACH 3->TABULATION
  --------------------------------------------------------

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
  //base cases in tabulation
    //dp[day][task performed]=max of other 2 tasks left
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

  for(int day=1; day<n; day++){
      for(int last=0; last<4; last++){
          dp[day][last]=0;
    for(int task=0; task<3; task++){
        if(task!=last){
        int point=points[day][task]+ dp[day-1][task];
       dp[day][last]=max(point,dp[day][last]);
                  }
              }
        }
      }
      return dp[n-1][3];

}
  
