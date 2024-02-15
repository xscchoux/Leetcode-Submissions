class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        map<int, int> count;
        for (auto interval:intervals) {
            count[interval[0]]++;
            count[interval[1]]--;
        }
        
        count[toBeRemoved[0]] -= 1;
        count[toBeRemoved[1]] += 1;
        
        vector<vector<int>> res;
        int running = 0;
        int start = INT_MIN;
        
        for (auto &[k, v]:count) {
            running += v;
            if (running == 1) {
                start = k;
            } else if (running == 0 && start != INT_MIN) {
                res.push_back({start, k});
                start = INT_MIN;
            }
        }
        return res;
    }
};