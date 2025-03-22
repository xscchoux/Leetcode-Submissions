using PII = pair<int, int>;
class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        unordered_set<int> markSet(begin(marked), end(marked));
        vector<vector<PII>> graph(n);

        for (auto &e:edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
        }

        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.emplace(0, s);
        vector<bool> visited(n, false);

        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            if (visited[node]) continue;
            if (markSet.contains(node)) return weight;
            visited[node] = true;

            for (auto &[nxt, w]:graph[node]) {
                pq.emplace(weight+w, nxt);
            }
        }

        return -1;
    }
};