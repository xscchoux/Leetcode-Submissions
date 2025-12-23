class Solution {
public:
    int maxDist = 0;
    void dfs(int curr, int parent, vector<vector<int>>& graph, int distance, vector<int>& dist) {
        if (distance > maxDist) maxDist = distance;
        dist[curr] = distance;
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            dfs(nxt, curr, graph, distance+1, dist);
        }
    }
    string findSpecialNodes(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> endpoint;

        vector<int> dist1(n, 0);
        dfs(0, -1, graph, 0, dist1);
        int farthest = 0;
        for (int i=0; i<n; i++) {
            if (dist1[i] == maxDist) {
                farthest = i;
                endpoint.push_back(i);
            }
        }

        vector<int> dist2(n, 0);
        dfs(farthest, -1, graph, 0, dist2);
        int maxDist = *max_element(begin(dist2), end(dist2));
        for (int i=0; i<n; i++) {
            if (dist2[i] == maxDist) {
                endpoint.push_back(i);
            }
        }

        string res = string(n, '0');

        for (int num:endpoint) {
            res[num] = '1';
        }

        return res;
    }
};