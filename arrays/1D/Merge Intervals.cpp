https://leetcode.com/problems/merge-intervals/description/
leetcode-56
  --------------------------
    BRUTE FORCE
  -------------------------

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         int n = intervals.size(); // size of the array

    //sort the given intervals:
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) { // select an interval:
        int start = intervals[i][0];
        int end = intervals[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
    }
};
T.C=O(N*logN) + O(2*N)
S.C=O(N)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ---------------------------------
        OPTIMAL
  ---------------------------------
  class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         int n = intervals.size(); // size of the array

    //sort the given intervals:
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
    }
};
 T.C=O(N*logN) + O(2*N)
S.C=O(N)
