using LL = long long;
class Solution {
public:
    int kMod = 1e9+7;
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
    vector<int> queryConversions(vector<vector<int>>& conversions, vector<vector<int>>& queries) {
        int N = conversions.size() + 1;
        vector<vector<pair<int, int>>> graph(N);
        vector<int> weight(N, 1);


        for (auto &c:conversions) {
            int u = c[0], v = c[1], w = c[2];
            graph[u].push_back({v, w});
        }

        queue<pair<int, int>> q;
        q.push({0, 1});  // {node ID, units that is equvalent to unit 0}

        while (!q.empty()) {
            auto [nodeID, preWeight] = q.front();
            q.pop();
            for (auto &[nxtID, currWeight]:graph[nodeID]) {
                weight[nxtID] = (LL)preWeight*currWeight%kMod;
                q.push({nxtID, weight[nxtID]});
            }
        }

        vector<int> res;
        for (auto &q:queries) {
            int u = q[0], v = q[1];
            res.push_back(powWithMod(weight[u], kMod-2, kMod)*weight[v]%kMod);
        }

        return res;
    }
};