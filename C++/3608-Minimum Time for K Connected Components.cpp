using PII = pair<int, int>;
struct UnionFind {
    vector<int> parent, rank;
    explicit UnionFind(int n) : parent(vector<int>(n)), rank(vector<int>(n, 1)) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    bool unite(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);
        if(p1 == p2) return false; // Same parent
        if(rank[p1] >= rank[p2]) {
            // Append p2 under p1
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        map<int, vector<PII>, greater<>> hmap;
        for (auto &e:edges) {
            hmap[e[2]].push_back({e[0], e[1]});
        }

        // before some t, u and v are connected
        // If when time < t, the number of connected componentes < k, return t
        UnionFind uf(n);
        int connected = n;

        for (auto &[time, vec]:hmap) {
            for (auto &[u, v]:vec) {
                if (uf.find(u) != uf.find(v)) {
                    uf.unite(u, v);
                    connected--;
                }
            }
            if (connected < k) return time;
        }

        return 0;
    }
};