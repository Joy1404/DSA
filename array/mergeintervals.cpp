#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};

    // Sort intervals based on the start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        // If the current interval overlaps with the last merged one, merge them
        if (!merged.empty() && start <= merged.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < intervals.size(); j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
        }
        merged.push_back({start, end});
    }
    return merged;
}
// optimal code
vector<vector<int>> mergeIntervalsOptimal(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};

    // Sort intervals based on the start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (merged.empty() ||  intervals[i][0] >merged.back()[1])
        {
            merged.push_back(intervals[i]);
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
    }
    return merged;
}

    int main()
    {
        vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        vector<vector<int>> merged = mergeIntervalsOptimal(intervals);

        for (const auto &interval : merged)
        {
            cout << "[" << interval[0] << ", " << interval[1] << "] ";
        }

        return 0;
    }