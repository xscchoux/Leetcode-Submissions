// First AC, brute-force DFS, very slow
class Solution {
public:
    void dfs(string curr, set<pair<string, string>>& visited, unordered_map<string, vector<pair<string, double>>>& graph, double val, unordered_map<string, double>& res) {
        res[curr] = max(res[curr], val);
        for (auto [nxt, rate]:graph[curr]) {
            if (!visited.contains({curr, nxt})) {
                visited.insert({curr, nxt});
                dfs(nxt, visited, graph, val*rate, res);
                visited.erase({curr, nxt});
            }
        }
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<pair<string, double>>> graph1;
        int N1 = pairs1.size();
        for (int i=0; i<N1; i++) {
            string u = pairs1[i][0], v = pairs1[i][1];
            graph1[u].push_back({v, rates1[i]});
            graph1[v].push_back({u, 1.0/rates1[i]});
        }
        unordered_map<string, double> res;
        set<pair<string, string>> visited;
        dfs(initialCurrency, visited, graph1, 1.0, res);

        unordered_map<string, vector<pair<string, double>>> graph2;
        int N2 = pairs2.size();
        for (int i=0; i<N2; i++) {
            string u = pairs2[i][0], v = pairs2[i][1];
            graph2[u].push_back({v, rates2[i]});
            graph2[v].push_back({u, 1.0/rates2[i]});
        }

        double ans = 1.0;
        for (auto &[k, v]:res) {
            unordered_map<string, double> res2;
            set<pair<string, string>> visited2;
            dfs(k, visited2, graph2, 1.0, res2);
            ans = max(ans, v*res2[initialCurrency]);
        }
        

        return ans;
    }
};



// two Dijkstra
class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        int N1 = pairs1.size(), N2 = pairs2.size();
        unordered_map<string, vector<pair<string, double>>> graph1;
        unordered_map<string, double> mx;
        for (int i=0; i<N1; i++) {
            graph1[pairs1[i][0]].push_back({pairs1[i][1], rates1[i]});
            graph1[pairs1[i][1]].push_back({pairs1[i][0], 1.0/rates1[i]});
        }

        priority_queue<pair<double, string>> pq;
        pq.push({1.0, initialCurrency});
        while (!pq.empty()) {
            auto [val, curr] = pq.top();
            pq.pop();
            if (mx[curr] != 0) continue;
            mx[curr] = val;
            for (auto &[nxt, rate]:graph1[curr]) {
                pq.push({val*rate, nxt});
            }
        }

        unordered_map<string, vector<pair<string, double>>> graph2;
        for (int i=0; i<N2; i++) {
            graph2[pairs2[i][0]].push_back({pairs2[i][1], rates2[i]});
            graph2[pairs2[i][1]].push_back({pairs2[i][0], 1.0/rates2[i]});
        }

        double res = 0.0;
        for (auto &[k, v]:mx) {
            priority_queue<pair<double, string>, vector<pair<double, string>>, greater<>> pq2;
            pq2.push({v, k});
            unordered_map<string, double> mx2;
            while (!pq2.empty()) {
                auto [val, curr] = pq2.top();
                pq2.pop();
                if (mx2[curr] != 0) continue;
                mx2[curr] = val;
                for (auto [nxt, rate]:graph2[curr]) {
                    pq2.push({val*rate, nxt});
                }
            }
            res = max(res, mx2[initialCurrency]);
        }
        return res;
    }
};