https://www.geeksforgeeks.org/problems/subset-sums2234/1
class Solution {
    void f(int start, int sum,vector<int>& arr,vector<int>& ans){
        if(start>=arr.size()){
            ans.push_back(sum);
            return;
        }
        
        //pick
        f(start+1,sum+arr[start],arr,ans);
        //not pick
        f(start+1,sum,arr,ans);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
      vector<int>ans;
      f(0,0,arr,ans);
      sort(ans.begin(), ans.end());
      return ans;
    }
};
T.C=O(2^N)
S.C=O(1)
