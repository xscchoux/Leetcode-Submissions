class Solution {
public:
    void dfs(int curr, int parent, vector<vector<int>>& graph, vector<int>& dist, int step) {
        dist[curr] = step;
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            dfs(nxt, curr, graph, dist, step+1);
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        int res = 0;
        vector<vector<int>> graph(n);

        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> distX(n), distY(n), distZ(n);

        dfs(x, -1, graph, distX, 0);
        dfs(y, -1, graph, distY, 0);
        dfs(z, -1, graph, distZ, 0);

        for (int i=0; i<n; i++) {
            vector<long long> arr;
            arr.push_back(distX[i]);
            arr.push_back(distY[i]);
            arr.push_back(distZ[i]);

            sort(begin(arr), end(arr));

            if (arr[0]*arr[0] + arr[1]*arr[1] == arr[2]*arr[2]) {
                res++;
            }
        }

        return res;
    }
};