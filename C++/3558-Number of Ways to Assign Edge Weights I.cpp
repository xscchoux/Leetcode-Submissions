using LL = long long;
class Solution {
public:
    int getDepth(int curr, int parent, vector<vector<int>>& graph) {
        
        int res = 0;
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            res = max(res, 1 + getDepth(nxt, curr, graph));
        }

        return res;
    }
    LL powWithMod(LL a, LL b, int kMod) {
        a %= kMod;
        LL res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int N = 1 + edges.size();
        long long res = 0;
        vector<vector<int>> graph(N+1);
        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int maxDepth = getDepth(1, -1, graph);

        return powWithMod(2, maxDepth-1, 1e9+7);
    }
};