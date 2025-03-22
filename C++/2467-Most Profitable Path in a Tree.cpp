// First AC, DFS then BFS
class Solution {
public:
    void dfs(int curr, vector<vector<int>>& graph, vector<int>& parent, int prev) {
        parent[curr] = prev;
        for (int nxt:graph[curr]) {
            if (nxt == prev) continue;
            dfs(nxt, graph, parent, curr);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int N = edges.size() + 1;
        vector<int> parent(N, -1);
        vector<vector<int>> graph(N);

        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // traverse from 0
        dfs(0, graph, parent, -1);

        vector<int> bobTime(N, INT_MAX); // node:time
        int t = 0;
        while (parent[bob] != -1) {
            bobTime[bob] = t;
            bob = parent[bob];
            t++;
        }

        int res = INT_MIN;
        t = 0;
        queue<tuple<int, int, int>> q;
        q.push({0, -1, amount[0]});
        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                auto [curr, parent, val] = q.front();
                q.pop();
                bool isLeaf = true;
                for (int nxt:graph[curr]) {
                    if (nxt == parent) continue;
                    isLeaf = false;
                    if (t+1 > bobTime[nxt]) {
                        q.push({nxt, curr, val});
                    } else if (t+1 == bobTime[nxt]) {
                        q.push({nxt, curr, val + amount[nxt]/2});
                    } else {
                        q.push({nxt, curr, val + amount[nxt]});
                    }
                }
                if (isLeaf) {
                    res = max(val, res);
                }
            }
            t++;
        }

        return res;
    }
};



// one DFS, really clever solution
class Solution {
public:
    int dfs(int curr, int parent, vector<vector<int>>& graph, int t, int bob, vector<int>& amount, vector<int>& distFromBob) {
        int maxChildSum = INT_MIN;  // maximum net income Alice can have from one of the subtrees

        if (curr == bob) distFromBob[curr] = 0;

        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            maxChildSum = max(maxChildSum, dfs(nxt, curr, graph, t+1, bob, amount, distFromBob));
            distFromBob[curr] = min(distFromBob[curr], 1+distFromBob[nxt]);
        }

        int currVal = 0;
        if (t == distFromBob[curr]) {
            currVal += amount[curr]/2;
        } else if (t < distFromBob[curr]) {
            currVal += amount[curr];
        }

        if (maxChildSum != INT_MIN) {
            return currVal + maxChildSum;
        } else {
            return currVal;
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int N = edges.size() + 1;
        vector<vector<int>> graph(N);
        vector<int> distFromBob(N, N); // distance from bob, also the time Bob travels from "node bob" to "curr"

        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        return dfs(0, -1, graph, 0, bob, amount, distFromBob);
    }
};