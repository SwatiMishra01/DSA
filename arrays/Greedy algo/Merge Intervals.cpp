https://leetcode.com/problems/merge-intervals/description/
leetcode-56
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       //step 1-> sort
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>>ans;

        //step 2-> pehla interval ans m daaldo
        ans.push_back(inetrvals[0]);
        
        for(int i=1; i<n; i++){
            //step 3->last interval jo ans mein h
            vector<int>&last=ans.back();
            //if overlapping->merge
           if(intervals[i][0]<=last[1])
           last[1]=max(last[1],intervals[i][1]);
           else
           ans.push_back(intervals[i]);
           
            }
        }
        return ans;
    }
};
T.C=O(n log n) + O(n) = O(n log n)
S.C=O(N)
