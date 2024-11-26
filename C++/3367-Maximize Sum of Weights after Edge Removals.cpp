using LL = long long;
class Solution {
public:
    int k;
    LL dfs(unordered_map<int, vector<pair<int, int>>>& graph, int curr, int parent, int connectParent, vector<vector<LL>>& memo) {
        if (memo[curr][connectParent] != -1LL) return memo[curr][connectParent];
        LL res = 0;
        vector<LL> diff;
        for (auto &[nxt, weight]:graph[curr]) {
            if (nxt == parent) continue;
            LL yes = weight + dfs(graph, nxt, curr, 1, memo);  // yes: Summing the best values from the next child's subtree and add the weight of edge to current node. Thus, child has at most k-1 edges.
            LL no = dfs(graph, nxt, curr, 0, memo);            // no:  Summing the best values from the next child's subtree and without adding the weight of edge to current node. Thus, child has at most k edges.
            res += no;
            diff.push_back(max(0LL, yes-no));
        }
        sort(begin(diff), end(diff), greater<>());
        if (connectParent) {
            for (int i=0; i<min(k-1, (int)diff.size()); i++) {
                res += diff[i];
            }
        } else {
            for (int i=0; i<min(k, (int)diff.size()); i++) {
                res += diff[i];
            }            
        }
        return memo[curr][connectParent] = res;
    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        this->k = k;
        int N = edges.size() + 1;
        vector<vector<LL>> memo(N, vector<LL>(2, -1LL));
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        return dfs(graph, 0, -1, 0, memo);
    }
};

// Use priority queue to keep the results of (yes-no)
using LL = long long;
class Solution {
public:
    int k;
    LL dfs(unordered_map<int, vector<pair<int, int>>>& graph, int curr, int parent, int connectParent, vector<vector<LL>>& memo) {
        if (memo[curr][connectParent] != -1LL) return memo[curr][connectParent];
        LL res = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto &[nxt, weight]:graph[curr]) {
            if (nxt == parent) continue;
            LL yes = weight + dfs(graph, nxt, curr, 1, memo);
            LL no = dfs(graph, nxt, curr, 0, memo);
            res += (yes>no)?yes:no;
            if (yes > no) pq.push(yes-no);
            if (pq.size() > k) {
                res -= pq.top();
                pq.pop();
            }
        }
        if (connectParent && pq.size() == k) res -= pq.top();

        return memo[curr][connectParent] = res;
    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        this->k = k;
        int N = edges.size() + 1;
        vector<vector<LL>> memo(N, vector<LL>(2, -1LL));
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        return dfs(graph, 0, -1, 0, memo);
    }
};

// return a pair (cases of "at most k edges" and "at most k-1 edges") in the DFS function. No need to use DP
using LL = long long;
class Solution {
public:
    int k;
    pair<LL, LL> dfs(unordered_map<int, vector<pair<int, int>>>& graph, int curr, int parent) {
        LL res = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto &[nxt, weight]:graph[curr]) {
            if (nxt == parent) continue;
            auto [yes, no] = dfs(graph, nxt, curr);  // yes: used the edge to parent and use at most k-1 child edges, no: without using the edge to parent and use at most k child edges
            yes += weight;
            res += (yes>no)?yes:no;
            if (yes > no) pq.push(yes-no);
            if (pq.size() > k) {
                res -= pq.top();
                pq.pop();
            }
        }

        LL without = res;
        if (pq.size() == k) without -= pq.top();

        return {without, res};
    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        this->k = k;
        int N = edges.size() + 1;
        vector<vector<LL>> memo(N, vector<LL>(2, -1LL));
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        return dfs(graph, 0, -1).second;
    }
};

