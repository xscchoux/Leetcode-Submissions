// O(n) union-find solution. Note the way we count components
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu(20002);
        for (auto &stone:stones) {
            int u = stone[0], v = stone[1];
            dsu.uni(u, v+10001);
        }

        return stones.size() - dsu.components;
    }
private:
    class DSU {
    public:
        int components;
        vector<int> parent, size;
        unordered_set<int> visited;
        DSU (int N) {
            for (int i=0; i<N; i++) parent.push_back(i);
            size.resize(N, 1);
            components = 0;
        }

        int find(int x) {
            if (!visited.contains(x)) {
                visited.insert(x);
                components++;
            }
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void uni(int a, int b) {
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                if (size[pa] > size[pb]) swap(pa, pb);
                parent[pa] = pb;
                size[pb] += size[pa];
                components--;
            }
        }
    };
};