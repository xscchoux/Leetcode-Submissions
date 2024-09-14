using PLI = pair<long long, int>;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n, 0);
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<>> rooms;
        for (int i=0; i<n; i++) rooms.push(i);

        priority_queue<PLI, vector<PLI>, greater<>> busy; // end time of running meetings {end_time, room index}
        
        for (auto &m:meetings) {
            int start = m[0], end = m[1];
            while (!busy.empty() && busy.top().first <= start) {
                auto [_, roomIdx] = busy.top();
                busy.pop();
                rooms.push(roomIdx);
            }
            if (!rooms.empty()) {
                int nxtIdx = rooms.top();
                rooms.pop();
                cnt[nxtIdx]++;
                busy.push({end, nxtIdx});
            } else {
                auto [nxtT, nxtIdx] = busy.top();
                busy.pop();
                cnt[nxtIdx]++;
                busy.push({nxtT+m[1]-m[0], nxtIdx});
            }
        }

        return max_element(begin(cnt), end(cnt)) - begin(cnt);
    }
};