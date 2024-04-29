using LL = long long;
class Solution {
public:
    void dfs(int curr, int parent, int mask, vector<vector<pair<int, int>>>& graph, string &s, unordered_map<LL, LL>& bitCount) {
        bitCount[mask]++;
        for (auto &[charNum, nxt]:graph[curr]) {
            if (nxt == parent) continue;
            dfs(nxt, curr, mask^(1<<charNum), graph, s, bitCount);
        }
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int N = parent.size();
        unordered_map<LL, LL> bitCount;
        vector<vector<pair<int, int>>> graph(N);

        for (int i=0; i<N; i++) {
            if (parent[i] != -1) {
                graph[parent[i]].push_back({s[i]-'a', i});
            }
        }

        dfs(0, -1, 0, graph, s, bitCount);
        
        LL res = 0;

        for (auto kv:bitCount) {
            int key = kv.first;
            res += bitCount[key]*(bitCount[key]-1);
            for (int i = 0; i<26; i++) {
                if (bitCount.find(key^(1<<i)) != bitCount.end()) {
                    res += bitCount[key]*bitCount[key^(1<<i)];
                }
            }
        }

        return res/2; //remove duplicates (0->1 and 1->0)
    }
};