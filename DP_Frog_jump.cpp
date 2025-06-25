

--------------------------------------------
    APPROACH-1 -> RECURSION   TLE
--------------------------------------------

#include <bits/stdc++.h> 
int f(int indx, vector<int> &heights){
    if(indx==0)
    return 0;

    int left= f(indx-1,heights)+abs(heights[indx]-heights[indx-1]);
    int right=INT_MAX;
    if(indx >1)
    right= f(indx-2,heights)+abs(heights[indx]-heights[indx-2]);
    return min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    return f(n-1,heights);
}
