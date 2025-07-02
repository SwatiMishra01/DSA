https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149

#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
        vector<int>ans;
        vector<bool> vis(m, false); //for visited of nums 2 initialised with 0
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr1[i]==arr2[j] && !vis[j]){
                ans.push_back(arr1[i]);
                vis[j]=true;
                break;
                }
                if(arr2[j]>arr1[i])
                break;
            }
        }
        return ans;
}
T.C=O(N1*N2)
S.C=O(N*N)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------
   2 POINTERS
  ------------------
  #include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
        int i=0; 
        int j=0;
        vector<int>ans;
        while(i<n && j<m){
        if(arr1[i]<arr2[j])
        i++;

        else if(arr2[j]<arr1[i])
        j++;

        else{
        ans.push_back(arr1[i]);
        i++;
        j++;
        }
        }

        return ans;
}
T.C=O(N1+N2)
S.C=O(1)
