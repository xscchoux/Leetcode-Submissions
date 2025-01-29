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
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);

        for (auto &e:edges) {
            int u = e[0], v = e[1];
            if (uf.find(u) == uf.find(v)) {
                return false;
            }
            uf.unite(u, v);
        }

        for (int i=1; i<n; i++) {
            if (uf.find(i) != uf.find(i-1)) return false;
        }

        return true;
    }
};


// topological sort, cannot detect separate trees
// class Solution {
// public:
//     bool validTree(int n, vector<vector<int>>& edges) {
//         vector<int> indegree(n);
//         vector<vector<int>> graph(n);
//         for (auto &e:edges) {
//             int u = e[0], v = e[1];
//             indegree[u]++;
//             indegree[v]++;
//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }

//         queue<int> q;
//         for (int i=0; i<n; i++) {
//             if (indegree[i] == 1) q.push(i);
//         }
//         int cnt = 0;
//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();
//             cnt++;
//             for (int nxt:graph[curr]) {
//                 if (indegree[nxt] == 0) continue;
//                 indegree[curr]--;
//                 indegree[nxt]--;
//                 if (indegree[nxt] == 1) {
//                     q.push(nxt);
//                 }
//             }
//         }

//         return cnt == n;
//     }
// };