class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    
    void uni(int a, int b, vector<int>& parent) {
        int pa = find(a, parent);
        int pb = find(b, parent);
        parent[pa] = pb;
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> parent(n);
        for (int i=0; i<n; i++) parent[i] = i;
        parent[firstPerson] = 0;
        
        sort(meetings.begin(), meetings.end(), [&] (vector<int>& a, vector<int>& b) { return a[2] < b[2];});
        
        
        map<int, vector<vector<int>>> hmap;
        for (auto &m:meetings) {
            hmap[m[2]].push_back({m[0], m[1]});
        }
        
        unordered_set<int> res;
        res.insert(0);
        res.insert(firstPerson);
        
        for (auto &kv:hmap) {
            
            for (auto &arr:kv.second) {
                uni(arr[0], arr[1], parent);
            }
            for (auto &arr:kv.second) {
                if (find(arr[0], parent) == find(0, parent)) {
                    res.insert(arr[0]);
                    res.insert(arr[1]);
                } else {
                    parent[arr[0]] = arr[0];
                    parent[arr[1]] = arr[1];                    
                }
            }
        
        }
        return vector<int>(res.begin(), res.end());
    }
};



// redo, add my solution (inefficient)
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
    void dfs(int curr, unordered_set<int>& visited, unordered_map<int, vector<int>>& graph, UnionFind& uf) {
        visited.insert(curr);
        uf.unite(0, curr);
        for (int nxt:graph[curr]) {
            if (!visited.contains(nxt)) {
                dfs(nxt, visited, graph, uf);
            }
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        UnionFind uf(n);
        sort(begin(meetings), end(meetings), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        map<int, vector<pair<int, int>>> hmap;
        for (auto &meeting:meetings) {
            int u = meeting[0], v = meeting[1], t = meeting[2];
            hmap[t].push_back({u, v});
        }

        uf.unite(0, firstPerson);

        for (auto &[t, vec]:hmap) {
            unordered_map<int, vector<int>> graph;
            unordered_set<int> visited, points;
            for (auto &[u, v]:vec) {
                points.insert(u);
                points.insert(v);
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

            for (auto it = points.begin(); it != points.end(); it++) {
                if (!visited.contains(*it) && uf.find(0) == uf.find(*it)) {
                    dfs(*it, visited, graph, uf);
                }
            }

        }
        vector<int> res;
        for (int i=0; i<n; i++) {
            if (uf.find(0) == uf.find(i)) {
                res.push_back(i);
            }
        }

        return res;
    }
};
