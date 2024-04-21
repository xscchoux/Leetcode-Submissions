class UnionFind {
    vector<int> rank, parent;
public:
    UnionFind(int n):parent(n) {
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 1);
    }
    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return find(parent[x]);
    }
    
    void uni(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            if (rank[px] > rank[py]) {
                swap(px, py);
            }
            parent[px] = py;
            rank[py] += rank[px];
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        
        for (auto &edge:edges) {
            int u = edge[0], v = edge[1];
            uf.uni(u, v);
        }
        
        return uf.find(source) == uf.find(destination);
    }
};