// https://leetcode.com/problems/count-connected-components-in-lcm-graph/
// map divisors to smallest indexes in nums where nums[index]%divisor == 0
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
    int countComponents(vector<int>& nums, int threshold) {
        sort(begin(nums), end(nums));

        int res = 0;
        while (!nums.empty() && nums.back() > threshold) {
            res++;
            nums.pop_back();
        }

        unordered_map<int, int> d; // divisor:smallest index in nums where nums[i]%divisor == 0
        int N = nums.size();
        UnionFind dsu(N);

        for (int i=0; i<N; i++) {
            for (int divisor=1; divisor*divisor<=nums[i]; divisor++) {
                if (nums[i]%divisor) continue;
                for (int common:vector<int>{divisor, nums[i]/divisor}) {
                    if (d.contains(common)) {
                        if (lcm(nums[i], nums[d[common]]) <= threshold) {
                            dsu.unite(d[common], i);
                        }
                    } else {
                        d[common] = i;
                    }
                }
            }
        }

        for (int i=0; i<N; i++) {
            if (dsu.find(i) == i) res++;
        }

        return res;
    }
};