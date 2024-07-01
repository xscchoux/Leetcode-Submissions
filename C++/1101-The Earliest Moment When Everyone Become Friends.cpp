struct DSU {
    int *rank, *parent;
    DSU(int n) {
        rank = new int[n];
        parent = new int[n];
        for (int i=0; i<n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    
    ~DSU() {
        delete[] rank;
        delete[] parent;
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void uni(int a, int b) {
        int pa = find(a), pb = find(b);
        if (rank[pa] > rank[pb]) {
            parent[pb] = pa;
        } else if (rank[pb] > rank[pa]) {
            parent[pa] = pb;
        } else {
            parent[pa] = pb;
            rank[pb]++;
        }
    }
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        int component = n;
        DSU uf(n);

        for (auto &log:logs) {
            int date = log[0], u = log[1], v = log[2];
            if (uf.find(u) != uf.find(v)) {
                uf.uni(u, v);
                component--;
            }
            if (component == 1) return date;
        }

        return -1;
    }
};