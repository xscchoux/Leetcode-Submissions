class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int res = 0;
        unordered_map<int, vector<int>> hmap;
        priority_queue<int, vector<int>, greater<>> pq;  // end day

        int endDay = -1;
        for (auto &e:events) {
            hmap[e[0]].push_back(e[1]);
            endDay = max(endDay, e[1]);
        }

        for (int day=1; day <= endDay; day++) {
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            if (hmap.contains(day)) {
                for (int endDay:hmap[day]) {
                    pq.push(endDay);
                }
            }
            if (!pq.empty()) {
                pq.pop();
                res++;
            }
        }

        return res;
    }
};