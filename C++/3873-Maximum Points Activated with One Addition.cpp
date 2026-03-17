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
    int maxActivated(vector<vector<int>>& points) {
        int N = points.size();
        UnionFind uf(N);
        unordered_map<int, vector<int>> xMap, yMap;
        
        for (int i=0; i<N; i++) {
            int x = points[i][0], y = points[i][1];
            xMap[x].push_back(i);
            yMap[y].push_back(i);
        }

        for (auto &[k, v]:xMap) {
            for (int i=1; i<v.size(); i++) {
                uf.unite(v[i], v[i-1]);
            }
        }

        for (auto &[k, v]:yMap) {
            for (int i=1; i<v.size(); i++) {
                uf.unite(v[i], v[i-1]);
            }
        }

        unordered_map<int, int> cnt;
        for (int i=0; i<N; i++) {
            int parent = uf.find(i);
            cnt[parent]++;
        }

        if (cnt.size() == 1) {
            return 1 + cnt.begin()->second;
        }

        int mx1 = 0, mx2 = 0;
        for (auto &[k, v]:cnt) {
            if (v > mx1) {
                mx2 = mx1;
                mx1 = v;
            } else if (v > mx2) {
                mx2 = v;
            }
        } 

        return mx1 + mx2 + 1;
    }
};