class Solution {
private:
    using PII = pair<int, int>;
    using PLI = pair<long long, int>;
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<PII, vector<PII>, greater<>> free;
        priority_queue<PLI, vector<PLI>, greater<>> working;
        // free:{weight of servers[i], i}, workding: {end time, index}
        for (int i=0; i<servers.size(); i++) {
            free.emplace(servers[i], i);
        }
        vector<int> res;
        long long t = 0;
        for (int i=0; i<tasks.size(); i++) {
            t = max((long long)i, t);
            while (!working.empty() && working.top().first <= t) {
                auto [_, ind] = working.top();
                working.pop();
                free.push({servers[ind], ind});
            }

            if (free.empty()) {
                long long endTime = working.top().first;
                t = endTime;
                
                while (!working.empty() && working.top().first <= t) {
                    auto [_, ind] = working.top();
                    working.pop();
                    free.push({servers[ind], ind});
                }
            }

            auto [w, ind] = free.top();
            free.pop();
            working.push({t+tasks[i], ind});
            res.push_back(ind);
        }

        return res;
    }
};