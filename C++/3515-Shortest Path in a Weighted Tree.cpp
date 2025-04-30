using PII = pair<int, int>;
class FenwickTree {
private:
    vector<int> bit; // Binary Indexed Tree
    int n;

public:
    // Constructor to initialize the Fenwick Tree with size `n`
    FenwickTree(int size) : n(size) {
        bit.resize(n + 1, 0); // 1-based indexing
    }

    // Add value `delta` at index `idx` (1-based index)
    void update(int idx, int delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx; // Move to the next index
        }
    }

    // Get the prefix sum from 1 to `idx` (1-based index)
    int query(int idx) const {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx; // Move to the parent index
        }
        return sum;
    }

    // Get the range sum from `left` to `right` (1-based index)
    int rangeQuery(int left, int right) const {
        return query(right) - query(left - 1);
    }
};
class Solution {
public:
    map<PII, int> edgeWeight;  // {parent, curr}:edge weight
    
    // fill t_in and t_out
    void dfs(int curr, int parent, vector<vector<PII>>& graph, vector<int>& t_in, vector<int>& t_out, int totDist, vector<int>& dist, int &time) {
        t_in[curr] = time;
        time++;  // time increases after going through an edge
        for (auto &[nxt, weight]:graph[curr]) {
            if (nxt == parent) continue;
            dist[nxt] = totDist + weight;
            dfs(nxt, curr, graph, t_in, t_out, totDist+weight, dist, time);
        }
        t_out[curr] = time-1;
        // Note that no time increase when moving backward. One can print out t_out to see.
    }

    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<PII>> graph(n+1);

        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
            if (u > v) swap(u, v);
            edgeWeight[{u, v}] = w;
        }

        vector<int> t_in(n+1), t_out(n+1), dist(n+1);
        int time = 1;
        dfs(1, 0, graph, t_in, t_out, 0, dist, time);
      
        vector<int> res;
        FenwickTree FT(n);

        for (auto &q:queries) {
            if (q[0] == 2) {
                res.push_back(dist[q[1]] + FT.query(t_in[q[1]]));
            } else {
                // update the Fenwick tree
                int u = q[1], v = q[2], newWeight = q[3];
                if (u > v) swap(u, v);
                int oldWeight = edgeWeight[{u, v}];
                edgeWeight[{u, v}] = newWeight;
                FT.update(t_in[v], newWeight-oldWeight);
                FT.update(t_out[v] + 1, oldWeight-newWeight);
            }
        }

        return res;
    }
};