class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        unordered_map<int, vector<int>> graph;
        vector<bool> visited(n);

        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        int cornerIdx = -1, maxDegree = 4;
        for (int i=0; i<n; i++) {
            if (indegree[i] == 1) {
                cornerIdx = i;
                break;
            } else if (indegree[i] < maxDegree) {
                cornerIdx = i;
                maxDegree = indegree[i];
            }
        }

        if (indegree[cornerIdx] == 1) {
            vector<vector<int>> res(1);
            int curr = cornerIdx;
            visited[curr] = true;
            while (true) {
                res[0].push_back(curr);
                int nxt = getNext(curr, graph, indegree, visited);
                if (nxt == -1) {
                    break;
                }
                visited[nxt] = true;
                curr = nxt;
            }
            return res;
        } else {
            vector<int> firstRow;
            int curr = cornerIdx;
            visited[curr] = true;
            while (true) {
                firstRow.push_back(curr);
                int nxt = getNext(curr, graph, indegree, visited);
                indegree[curr]--;
                indegree[nxt]--;
                visited[nxt] = true;
                if (indegree[nxt] == 1) {
                    firstRow.push_back(nxt);
                    break;
                }
                curr = nxt;
            }

            int col = firstRow.size(), row = n/col;
            vector<vector<int>> res(row, vector<int>(col, 0));
            res[0] = firstRow;
            for (int r=1; r<row; r++) {
                for (int c=0; c<col; c++) {
                    int prev = res[r-1][c];
                    int curr = getNext(prev, graph, indegree, visited);
                    indegree[prev]--;
                    indegree[curr]--;
                    visited[curr] = true;
                    res[r][c] = curr;                  
                }
            }

            return res;
        }

    }

    int getNext(int idx, unordered_map<int, vector<int>>& graph, vector<int>& indegree, vector<bool>& visited) {
        int edgeCnt = INT_MAX;
        int nxtIdx = -1;
        for (int nxt:graph[idx]) {
            if (!visited[nxt] && indegree[nxt] < edgeCnt) {
                edgeCnt = indegree[nxt];
                nxtIdx = nxt;
            }
        }
        return nxtIdx;
    }
};