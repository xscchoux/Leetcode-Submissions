/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int N = schedule.size();
        vector<vector<int>> arr;

        for (int i=0; i<N; i++) {
            for (int j=0; j<schedule[i].size(); j++) {
                arr.push_back({schedule[i][j].start, schedule[i][j].end});
            }
        }

        sort(begin(arr), end(arr));
        // merge intervals
        vector<vector<int>> merged;
        for (int i=0; i<arr.size(); i++) {
            if (merged.empty() || arr[i][0] > merged.back()[1]) {
                merged.push_back(arr[i]);
            } else {
                merged.back()[1] = max(arr[i][1], merged.back()[1]);
            }
        }

        // check free time
        vector<Interval> res; 
        for (int i=1; i<merged.size(); i++) {
            res.push_back(Interval(merged[i-1][1], merged[i][0]));
        }

        return res;
    }
};



// A little faster
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        int N = schedule.size();
        vector<array<int, 2>> arr;

        for (int i=0; i<N; i++) {
            for (int j=0; j<schedule[i].size(); j++) {
                arr.push_back({schedule[i][j].start, schedule[i][j].end});
            }
        }

        sort(begin(arr), end(arr));

        vector<Interval> res;

        int endTime = arr[0][1];
        for (int i=1; i<arr.size(); i++) {
            if (arr[i][0] > endTime) {
                res.push_back(Interval(endTime, arr[i][0]));
                endTime = arr[i][1];
            } else {
                endTime = max(endTime, arr[i][1]);
            }
        }

        return res;
    }
};