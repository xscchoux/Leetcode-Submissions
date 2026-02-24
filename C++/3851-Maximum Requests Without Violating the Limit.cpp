class Solution {
public:
    int maxRequests(vector<vector<int>>& requests, int k, int window) {
        unordered_map<int, vector<int>> hmap;
        for (const auto &r:requests) {
            int u = r[0], v = r[1];
            hmap[u].push_back(v);
        }

        int removed = 0;
        for (auto &[_, val]:hmap) {
            if (val.size() <= k) {
                continue;
            }
            sort(begin(val), end(val));

            deque<int> dq;
            for (int i=0; i<val.size(); i++) {
                dq.push_back(val[i]);
                if (dq.back() - dq.front() > window) {
                    dq.pop_front();
                }
                if (dq.size() > k) {
                    dq.pop_back();
                    removed++;
                }
            }
        }

        return requests.size() - removed;
    }
};