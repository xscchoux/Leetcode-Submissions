class Solution {
public:
    long long maxProfit(vector<int>& workers, vector<vector<int>>& tasks) {
        unordered_map<int, priority_queue<int>> hmap;
        for (auto &t:tasks) {
            hmap[t[0]].push(t[1]);
        }

        long long res = 0;
        for (int i=0; i<workers.size(); i++) {
            int val = workers[i];
            if (!hmap[val].empty()) {
                res += hmap[val].top();
                hmap[val].pop();
            }
        }
        
        int excess = 0;
        for (auto &[k, v]:hmap) {
            if (!v.empty()) {
                excess = max(excess, hmap[k].top());
            }
        }

        return res+excess;
    }
};