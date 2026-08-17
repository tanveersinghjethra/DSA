class Solution {
public:

    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n == 0)
            return 0;

        // Sort according to ending time
        sort(intervals.begin(), intervals.end(), comparator);

        int cnt = 1;
        int lastend_time = intervals[0][1];

        for (int i = 1; i < n; i++) {

            // Non-overlapping interval
            if (intervals[i][0] >= lastend_time) {
                cnt++;
                lastend_time = intervals[i][1];
            }
        }

        // Remove overlapping intervals
        return n - cnt;
    }
};