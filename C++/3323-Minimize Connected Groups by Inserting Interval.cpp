// merge intervals + binary search
class Solution {
public:
    int minConnectedGroups(vector<vector<int>>& intervals, int k) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> arr;
        for (auto interval:intervals) {
            int u = interval[0], v = interval[1];
            if (!arr.empty() && u <= arr.back()[1]) {
                arr.back()[1] = max(arr.back()[1], v);
            } else {
                arr.push_back(interval);
            }
        }

        vector<int> prePos;
        int res = arr.size();
        for (int i=0; i<arr.size(); i++) {
            auto &x = arr[i];
            if (!prePos.empty()) {
                int idx = lower_bound(prePos.begin(), prePos.end(), x[0]-k) - prePos.begin();
                res = min(res, (int)arr.size()-(i-idx));
            }
            prePos.push_back(x[1]);
        }

        return res;
    }
};


// merge intervals + sliding window
class Solution {
public:
    int minConnectedGroups(vector<vector<int>>& intervals, int k) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> arr;
        for (auto interval:intervals) {
            int u = interval[0], v = interval[1];
            if (!arr.empty() && u <= arr.back()[1]) {
                arr.back()[1] = max(arr.back()[1], v);
            } else {
                arr.push_back(interval);
            }
        }

        int n = arr.size(), res = n;
        for (int i=0, j=0; i<n; i++) {
            while (j<n && arr[i][1]+k >= arr[j][0]) {
                j++;
            }
            res = min(res, n-(j-i-1));
        }

        return res;
    }
};