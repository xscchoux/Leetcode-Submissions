using LL = long long;
class Solution {
public:
    int kMod = 1e9+7, N, maxPower;

    // for each node, get binaryLifting[curr][0]
    void traversal(int curr, int parent, vector<vector<int>>& graph, vector<vector<int>>& binaryLifting, vector<int>& depth, int d) {
        binaryLifting[curr][0] = parent;
        depth[curr] = d;
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            traversal(nxt, curr, graph, binaryLifting, depth, d+1);
        }
    }

    // for each node, get binaryLifting[curr][1~maxPower]
    void build(vector<vector<int>>& binaryLifting) {
        for (int power=1; power<=maxPower; power++) {
            for (int curr=1; curr<=N; curr++) {
                if (binaryLifting[curr][power-1] == -1) continue;
                binaryLifting[curr][power] = binaryLifting[binaryLifting[curr][power-1]][power-1];
            }
        }
    }

    // get LCA of u and v
    int getLCA(int u, int v, vector<vector<int>>& binaryLifting, vector<int>& depth) {

        // move u to the same level as v
        for (int jump = maxPower; jump>=0; jump--) {
            int diffD = depth[u] - depth[v];
            if (diffD < (1<<jump)) {
                continue;
            }
            u = binaryLifting[u][jump];
        }
        if (u == v) return u;

        // find common parent node
        for (int jump = maxPower; jump>=0; jump--) {
            if (binaryLifting[u][jump] != binaryLifting[v][jump]) {
                u = binaryLifting[u][jump];
                v = binaryLifting[v][jump];
            }
        } 

        return binaryLifting[u][0];
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

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        this->N = edges.size() + 1;
        this->maxPower = log2(N-1);
        vector<vector<int>> binaryLifting(N+1, vector<int>(maxPower+1, -1));
        vector<int> depth(N+1, -1);

        vector<vector<int>> graph(N+1);
        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        traversal(1, -1, graph, binaryLifting, depth, 0);
        build(binaryLifting);
        vector<int> res;

        for (auto &q:queries) {
            int u = q[0], v = q[1];
            if (u == v) {
                res.push_back(0);
                continue;
            }

            if (depth[u] < depth[v]) swap(u, v);
            int LCA = getLCA(u, v, binaryLifting, depth);

            int dist = depth[u] + depth[v] - 2*depth[LCA];

            res.push_back(powWithMod(2, dist-1, kMod));
        }

        return res;
    }
};