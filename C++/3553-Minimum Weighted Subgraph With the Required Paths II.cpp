class Solution {
public:
    int N, maxN;
    void getLevel(int curr, int parent, vector<vector<pair<int, int>>>& graph, vector<vector<int>>& binaryLifting, vector<int>& depth, vector<int>& weightSum, int d, int w) {
        depth[curr] = d;
        weightSum[curr] = w;
        binaryLifting[curr][0] = parent;
        for (auto &[nxt, weight]:graph[curr]) {
            if (nxt == parent) continue;
            getLevel(nxt, curr, graph, binaryLifting, depth, weightSum, d+1, w+weight);
        }
    }
    void fillBinaryLifting(vector<vector<int>>& binaryLifting) {
        for (int power=1; power<=maxN; power++) {
            for (int i=0; i<N; i++) {
                if (binaryLifting[i][power-1] == -1) continue;
                binaryLifting[i][power] = binaryLifting[binaryLifting[i][power-1]][power-1];
            }
        }
    }

    int findLCA(int u, int v, vector<vector<int>>& binaryLifting, vector<int>& depth) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        while (diff > 0) {
            for (int power = maxN; power>=0; power--) {
                if ((1<<power)>diff) continue;
                diff -= (1<<power);
                u = binaryLifting[u][power];
            }
        }
        if (u == v) return u;

        for (int power=maxN; power>=0; power--) {
            if (binaryLifting[u][power] == binaryLifting[v][power]) continue;
            u = binaryLifting[u][power];
            v = binaryLifting[v][power];
        }
        return binaryLifting[u][0];
    }
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        this->N = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(N);
        for (auto &e:edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        this->maxN = log2(N-1);
        vector<vector<int>> binaryLifting(N, vector<int>(maxN+1, -1));

        vector<int> depth(N, -1), weightSum(N, 0);
        getLevel(0, -1, graph, binaryLifting, depth, weightSum, 0, 0);
        fillBinaryLifting(binaryLifting);

        vector<int> res;
        for (auto &q:queries) {
            int src1 = q[0], src2 = q[1], dest = q[2];
            int lca1 = findLCA(src1, src2, binaryLifting, depth);
            int lca2 = findLCA(src1, dest, binaryLifting, depth);
            int lca3 = findLCA(src2, dest, binaryLifting, depth);

            // weight sum of every two nodes
            int weight1 = (weightSum[src1] + weightSum[src2] - 2*weightSum[lca1]);
            int weight2 = (weightSum[src1] + weightSum[dest] - 2*weightSum[lca2]);
            int weight3 = (weightSum[src2] + weightSum[dest] - 2*weightSum[lca3]);
            res.push_back((weight1 + weight2 + weight3)/2);  // every edge will be visited twice
        }

        return res;
    }
};