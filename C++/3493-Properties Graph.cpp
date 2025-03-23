// first AC, slow
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
    int k;
    int intersect(vector<int>& a, vector<int>& b) {
        unordered_set<int> setA(begin(a), end(a));
        unordered_set<int> setB(begin(b), end(b));
        int cnt = 0;
        for (auto it = setA.begin(); it != setA.end(); it++) {
            if (setB.contains(*it)) {
                cnt++;
            }
            if (cnt == k) return k;
        }

        return cnt;
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        this->k = k;
        int N = properties.size();
        UnionFind uf(N);

        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (uf.find(i) != uf.find(j) && intersect(properties[i], properties[j]) >= k) {
                    uf.unite(i, j);
                }
            }
        }

        int res = 0;
        for (int i=0; i<N; i++) {
            if (i == uf.find(i)) res++;
        }

        return res;
    }
};




// Use bitset, much faster
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
    int k;
    int intersect(vector<int>& a, vector<int>& b) {
        unordered_set<int> setA(begin(a), end(a));
        unordered_set<int> setB(begin(b), end(b));
        int cnt = 0;
        for (auto it = setA.begin(); it != setA.end(); it++) {
            if (setB.contains(*it)) {
                cnt++;
            }
            if (cnt == k) return k;
        }

        return cnt;
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        this->k = k;
        int N = properties.size();
        UnionFind uf(N);
        vector<bitset<101>> bits(N);

        for (int i=0; i<N; i++) {
            for (int j:properties[i]) bits[i].set(j);
        }


        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                const auto tmp = (bits[i] & bits[j]);
                if (tmp.count() >= k) {
                    uf.unite(i, j);
                }
            }
        }

        int res = 0;
        for (int i=0; i<N; i++) {
            if (i == uf.find(i)) res++;
        }

        return res;
    }
};