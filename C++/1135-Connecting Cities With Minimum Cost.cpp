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
    int minimumCost(int n, vector<vector<int>>& connections) {
        UnionFind uf(n+1);
        sort(begin(connections), end(connections), [&](auto &a, auto &b) {
            return a[2] < b[2];
        });
        
        int cnt = 0, res = 0;

        for (auto &c:connections) {
            int u = c[0], v = c[1], w = c[2];
            if (uf.find(u)!= uf.find(v)) {
                uf.unite(u, v);
                cnt++;
                res += w;
            }
        }

        return (n-cnt) == 1?res:-1;
    }
};