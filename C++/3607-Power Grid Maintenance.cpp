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
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind uf(c+1);

        for (auto &p:connections) {
            uf.unite(p[0], p[1]);
        }

        vector<priority_queue<int, vector<int>, greater<>>> allGroups(c+1);
        for (int p=1; p<=c; p++) {
            int groupID = uf.find(p);
            allGroups[groupID].push(p);
        }

        vector<bool> online(c+1, true);
        vector<int> res;
        
        for (auto &q:queries) {
            if (q[0] == 1) {
                if (online[q[1]]) res.push_back(q[1]);
                else {
                    int groupID = uf.find(q[1]);
                    while (!allGroups[groupID].empty() && online[allGroups[groupID].top()] == false) {
                        allGroups[groupID].pop();
                    }
                    if (allGroups[groupID].empty()) res.push_back(-1);
                    else res.push_back(allGroups[groupID].top());
                }
            } else {
                online[q[1]] = false;
            }
        }

        return res;
    }
};