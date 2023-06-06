#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() <= 1)
        return intervals;

    // Sort the intervals
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    vector<int> prev = intervals[0];
    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> cur = intervals[i];
        // Expand previous interval if possible
        if (cur[0] <= prev[1])
        {
            // Expand prev
            prev[1] = max(prev[1], cur[1]);
        }
        else
        {
            // prev interval cannot be expanded;Add it to the ans
            ans.push_back(prev);
            // Consider next interval for expansion
            prev = cur;
        }
    }
    // Add the last interval
    ans.push_back(prev);

    return ans;
}

