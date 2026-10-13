// O((N-1)!)
class Solution {
public:
    int res = INT_MAX, N;
    void dfs(int start, int count, vector<int>& val) {
        while (start < N && val[start] == 0) {
            start++;
        }

        if (start == N) {
            res = min(res, count);
            return;
        }

        if (count > res) {
            return;
        }

        for (int nxt=start+1; nxt<N; nxt++) {
            if (val[start] * val[nxt] < 0) {
                val[nxt] += val[start];
                dfs(start+1, count+1, val);
                val[nxt] -= val[start];
            }

            if (val[start] + val[nxt] == 0) {  // pruning
                break;
            }
        }


    }
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> hmap;
        for (auto &t:transactions) {
            int u = t[0], v = t[1], w = t[2];
            hmap[u] -= w;
            hmap[v] += w;
        }

        vector<int> val;
        for (auto &[k, v]:hmap) {
            if (v != 0) {
                val.push_back(v);
            }
        }

        this->N = val.size();
        if (N == 0) {
            return 0;
        }

        dfs(0, 0, val);

        return res;
    }
};