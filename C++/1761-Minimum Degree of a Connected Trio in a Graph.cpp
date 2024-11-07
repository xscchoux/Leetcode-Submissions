// O(n^3, adjacent matrix)
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, 0));
        vector<int> indegree(n+1);

        for (auto &edge:edges) {
            int u = edge[0], v = edge[1];
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;
            indegree[u]++;
            indegree[v]++;
        }

        int res = INT_MAX;
        for (int a=1; a<=n; a++) {
            for (int b=a+1; b<=n; b++) {
                if (!adjMatrix[a][b]) continue;
                for (int c=b+1; c<=n; c++) {
                    if (adjMatrix[a][c] && adjMatrix[b][c]) {
                        res = min(res, indegree[a]+indegree[b]+indegree[c]-6);
                    }
                }
            }
        }
        
        return res < INT_MAX?res:-1;
    }
};