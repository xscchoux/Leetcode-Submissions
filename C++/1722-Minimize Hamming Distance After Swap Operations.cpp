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
    int cal(vector<int>& index, vector<int>& source, vector<int>& target) {
        vector<int> srcArr, tgtArr;
        for (int c:index) {
            srcArr.push_back(source[c]);
            tgtArr.push_back(target[c]);
        }

        sort(begin(srcArr), end(srcArr));
        sort(begin(tgtArr), end(tgtArr));

        int common = 0, i = 0, j = 0;
        while (i < srcArr.size() && j < tgtArr.size()) {
            if (srcArr[i] == tgtArr[j]) {
                common++;
                i++;
                j++;
            } else if (srcArr[i] < tgtArr[j]) {
                i++;
            } else {
                j++;
            }
        }

        return index.size() - common;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int N = source.size();
        UnionFind uf(N);

        for (auto &a:allowedSwaps) {
            int u = a[0], v = a[1];
            uf.unite(u, v);
        }

        unordered_map<int, vector<int>> hmap;
        for (int i=0; i<N; i++) {
            int p = uf.find(i);
            hmap[p].push_back(i);
        }

        int res = 0;
        for (auto &[k, v]:hmap) {
            res += cal(v, source, target);
        }

        return res;
    }
};