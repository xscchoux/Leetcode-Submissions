class Solution {
public:
    int dfs(int curr, int parent, int w, int signalSpeed, vector<vector<pair<int, int>>>& graph) {
        int cnt = (w%signalSpeed)?0:1;
        for (auto [nxt, weight]:graph[curr]) {
            if (nxt == parent) continue;
            cnt += dfs(nxt, curr, w + weight, signalSpeed, graph);
        }
        return cnt;
    }
    
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        vector<int> res(edges.size()+1);
        vector<vector<pair<int, int>>> graph(edges.size()+1);
        for (vector<int> edge:edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        for (int i=0; i<=edges.size(); i++) {
            if (graph[i].size() < 2) continue;
            int tot = 0, cnt = 0;
            for (auto [nxt, weight]:graph[i]) {
                int curr_cnt = dfs(nxt, i, weight, signalSpeed, graph);
                tot += cnt*curr_cnt;
                cnt += curr_cnt;
            }
            res[i] = tot;
        }
        return res;
    }
};