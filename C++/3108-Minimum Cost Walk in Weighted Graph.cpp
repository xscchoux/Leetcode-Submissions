class Solution {
private:
    vector<int> parent;
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) return parent[x];
        return parent[x] = find(parent, parent[x]);
    }
    
    void uni(vector<int>& parent, int a, int b) {
        int pa = find(parent, a);
        int pb = find(parent, b);
        parent[pa] = pb;
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        for (int i=0; i<n; i++) parent[i] = i;
        
        unordered_map<int, int> val;
        
        unordered_map<int, vector<int>> adjWeight;
        for (auto edge:edges) {
            int curr = edge[0], nxt = edge[1], weight = edge[2];
            adjWeight[curr].push_back(weight);
            uni(parent, curr, nxt);
        }
        
        for (int i=0; i<n; i++) {
            int p = find(parent, i);
            if (val.find(p) == val.end()) val[p] = INT_MAX;
            for (int v:adjWeight[i]) {
                val[p] = val[p]&v;
            }
        }
        
        vector<int> res;
        for (auto q:query) {
            int s = q[0], e = q[1];
            int ps = find(parent, s), pe = find(parent, e);
            if (ps != pe) {
                res.push_back(-1);
            } else {
                res.push_back(val[ps]);
            }
        }
        
        return res;
    }
};



// Redo, this is much faster
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind uf(n);

        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            uf.unite(u, v);
        }

        vector<int> res;
        vector<int> val(n, -1);  // note this trick, we use -1

        // calculate AND values of all connected components
        for (auto &e:edges) {
            int root = uf.find(e[0]);
            val[root] &= e[2];
        }


        for (auto &q:query) {
            int u = q[0], v = q[1];
            if (uf.find(u) != uf.find(v)) res.push_back(-1);
            else {
                int root = uf.find(u);
                res.push_back(val[root]);
            }
        }

        return res;
    }
};