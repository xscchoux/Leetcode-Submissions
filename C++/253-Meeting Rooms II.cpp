class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0, ans = 0;
        vector<pair<int, int>> arr;
        for (auto interval:intervals) {
            arr.push_back({interval[0], 1});
            arr.push_back({interval[1], -1});
        }
        
        sort(arr.begin(), arr.end());
        
        for (auto p:arr) {
            if (p.second == -1) res--;
            else res++;
            ans = max(res, ans);
        }
        return ans;
    }
};