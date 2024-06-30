class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (x != parent[x]) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    void uni(vector<int>& parent, int a, int b) {
        int pa = find(parent, a), pb = find(parent, b);
        if (pa != pb) {
            parent[pa] = parent[pb];
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> edgeMap;
        for (auto &edge:edges) {
            int t = edge[0], u = edge[1], v = edge[2];
            edgeMap[t].push_back({u, v});
        }

        int res = 0;
        vector<int> parentA(n+1);
        vector<int> parentB(n+1);
        int componentA = n, componentB = n;

        for (int i=1; i<=n; i++) {
            parentA[i] = i;
            parentB[i] = i; 
        }

        for (auto &p:edgeMap[3]) {
            int u = p.first, v = p.second;
            if (find(parentA, u) != find(parentA, v)) {
                uni(parentA, u, v);
                uni(parentB, u, v);
                componentA--; componentB--;
            } else {
                res++;
            }
        }

        for (auto &p:edgeMap[1]) {
            int u = p.first, v = p.second;
            if (find(parentA, u) != find(parentA, v)) {
                uni(parentA, u, v);
                componentA--;
            } else {
                res++;
            }
        }

        for (auto &p:edgeMap[2]) {
            int u = p.first, v = p.second;
            if (find(parentB, u) != find(parentB, v)) {
                uni(parentB, u, v);
                componentB--;
            } else {
                res++;
            }
        }

        if (componentA != 1 || componentB != 1) return -1;

        return res;
    }
};