https://leetcode.com/problems/non-overlapping-intervals/description/
LEETCODE-435
  
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;

    // Sort by end time
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });

    int count = 1; // count of non-overlapping intervals
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= end) {
            count++;
            end = intervals[i][1];
        }
    }

    return intervals.size() - count; // min removals
    }
};

T.C=O(N)+O(N LOG N)
S.C=O(1)
