class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {newInterval};
        
        vector<vector<int>> res;
        int N = intervals.size(), left = 0, right = N-1;
        
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (intervals[mid][0] < newInterval[0]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        int last;
        if (intervals[right][0] < newInterval[0]) {
            last = right; 
        } else if (intervals[left][0] < newInterval[0]) {
            last = left;
        } else {
            last = -1;
        }

        intervals.insert(intervals.begin() + last + 1, newInterval); // last + 1 is the index of newInterval in the updated intervals vector
        
        for (auto& interval:intervals) {
            if (!res.empty() && res.back()[1] >= interval[0]) {
                res.back()[1] = max(res.back()[1], interval[1]);
            } else {
                res.push_back(interval);
            }
        }
        
        return res;
    }
};