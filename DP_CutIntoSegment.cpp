# https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM


------!!! WILL SHOW TIME LIMIT EXCEEDED!!!---------------------------

#include<limits.h>
int solve(int n, int x, int y, int z){
	//base case
	if(n==0)
	return 0;

	if(n<0)
	return INT_MIN;

	int a=solve(n-x,x,y,z)+1 ;
	int b=solve(n-y,x,y,z)+1 ;
	int c=solve(n-z,x,y,z)+1 ;

	return max(a,max(b,c));
}
int cutSegments(int n, int x, int y, int z) {
 int  ans= solve(n,x,y,z);


 if(ans<0)
 return 0;
 else
 return ans;
}



  ------------------------------------------------------------------------------------------------------------------
