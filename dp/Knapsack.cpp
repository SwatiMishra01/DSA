
--------------------------------------------
 APPROACH 1-> RECURSION  (TLE)
----------------------------------------------
#include <bits/stdc++.h> 
int f(int indx,int maxWeight,vector<int> &weight,vector<int> &value){
	//base cases
	if(indx==0){
		if(weight[indx]<=maxWeight)
		return value[0];
		else
		return 0;
	}


	//explore all possibilities
	int not_take=0+f(indx-1,maxWeight,weight,value);
	int take=INT_MIN; //since it is max porblem so it will nto choose this path
	if(weight[indx]<=maxWeight)
	take= value[indx]+f(indx-1,maxWeight-weight[indx],weight,value);


	//return max
	return max(take,not_take);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
 return f(n-1,maxWeight,weight,value);
}
