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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionFind uf(n);

        for (int i=1; i<n; i++) {
            if (nums[i] - nums[i-1] <= maxDiff) {
                uf.unite(i, i-1);
            }
        }

        vector<bool> res;
        for (auto &q:queries) {
            int u = q[0], v = q[1];
            if (uf.find(u) != uf.find(v)) {
                res.push_back(false);
            } else {
                res.push_back(true);
            }
        }

        return res;
    }
};