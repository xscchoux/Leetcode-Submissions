class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<>> pq;

        for (auto &interval:intervals) {
            int u = interval[0], v = interval[1];
            if (pq.empty() || u <= pq.top()) {
                pq.push(v);
            } else {
                pq.pop();
                pq.push(v);
            }
        }

        return pq.size();
    }
};