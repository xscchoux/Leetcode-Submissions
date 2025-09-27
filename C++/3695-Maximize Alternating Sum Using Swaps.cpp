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
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int N = nums.size();
        UnionFind uf(N);
        for (auto &swap:swaps) {
            uf.unite(swap[0], swap[1]);
        }

        unordered_map<int, deque<int>> hmap;
        for (int i=0; i<nums.size(); i++) {
            hmap[uf.find(i)].push_back({nums[i]});
        }

        for (auto &[k, v]:hmap) {
            sort(begin(v), end(v));
        }

        long long res = 0;
        for (int i=0; i<nums.size(); i++) {
            int parent = uf.find(i);
            if (i%2) {
                res -= hmap[parent].front();
                hmap[parent].pop_front();
            } else {
                res += hmap[parent].back();
                hmap[parent].pop_back();                
            }
        }

        return res;
    }
};