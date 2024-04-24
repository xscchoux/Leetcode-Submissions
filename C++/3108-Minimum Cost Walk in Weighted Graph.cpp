class Solution {
private:
    vector<int> parent;
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) return parent[x];
        return parent[x] = find(parent, parent[x]);
    }
    
    void uni(vector<int>& parent, int a, int b) {
        int pa = find(parent, a);
        int pb = find(parent, b);
        parent[pa] = pb;
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        for (int i=0; i<n; i++) parent[i] = i;
        
        unordered_map<int, int> val;
        
        unordered_map<int, vector<int>> adjWeight;
        for (auto edge:edges) {
            int curr = edge[0], nxt = edge[1], weight = edge[2];
            adjWeight[curr].push_back(weight);
            uni(parent, curr, nxt);
        }
        
        for (int i=0; i<n; i++) {
            int p = find(parent, i);
            if (val.find(p) == val.end()) val[p] = INT_MAX;
            for (int v:adjWeight[i]) {
                val[p] = val[p]&v;
            }
        }
        
        vector<int> res;
        for (auto q:query) {
            int s = q[0], e = q[1];
            int ps = find(parent, s), pe = find(parent, e);
            if (ps != pe) {
                res.push_back(-1);
            } else {
                res.push_back(val[ps]);
            }
        }
        
        return res;
    }
};