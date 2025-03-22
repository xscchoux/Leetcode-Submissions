// First AC
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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        UnionFind uf(n);

        for (auto &e:edges) {
            int u = e[0], v = e[1];
            indegree[u]++; indegree[v]++;
            uf.unite(u, v);
        }

        unordered_map<int, vector<int>> cnt;

        for (int i=0; i<n; i++) {
            cnt[uf.find(i)].push_back(i);
        }

        int res = 0;
        for (auto &[k, v]:cnt) {
            bool isOK = true;
            for (int node:v) {
                if (indegree[node] != v.size() - 1) {
                    isOK = false;
                    break;
                }
            }
            if (isOK) {
                res++;
            }
        }

        return res;
    }
};


// Better
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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        unordered_map<int, int> edgeCnt;

        for (auto &e:edges) {
            int u = e[0], v = e[1];
            uf.unite(u, v);
        }

        for (auto &e:edges) {
            edgeCnt[uf.find(e[0])]++;
        }

        int res = 0;
        for (int i=0; i<n; i++) {
            if (uf.find(i) == i) {  // i is a root
                int sz = uf.rank[i];
                if (edgeCnt[i] == sz*(sz-1)/2) {
                    res++;
                }
            }
        }

        return res;
    }
};