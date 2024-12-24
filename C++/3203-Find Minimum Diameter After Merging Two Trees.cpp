// First AC, lengthy. Use topological sort + two DFS
class Solution {
public:
    void dfs(int node, int parent, int& maxDist, int& maxNode, int dist, vector<vector<int>>& graph) {
        if (dist > maxDist) {
            maxDist = dist;
            maxNode = node;
        }

        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, maxDist, maxNode, dist + 1, graph);
            }
        }
    }

    int findDiameter(vector<vector<int>>& graph) {
        int maxDist = 0, maxNode = 0;
        dfs(0, -1, maxDist, maxNode, 0, graph);  // First DFS
        dfs(maxNode, -1, maxDist, maxNode, 0, graph);  // Second DFS
        return maxDist;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size(), m = edges2.size();
        vector<int> indegree1(n+1, 0), indegree2(m+1, 0);
        vector<vector<int>> graph1(n+1), graph2(m+1);

        for (auto &e:edges1) {
            int u = e[0], v = e[1];
            graph1[u].push_back(v);
            graph1[v].push_back(u);
            indegree1[u]++;
            indegree1[v]++;
        }

        for (auto &e:edges2) {
            int u = e[0], v = e[1];
            graph2[u].push_back(v);
            graph2[v].push_back(u);
            indegree2[u]++;
            indegree2[v]++;
        }

        int d1 = findDiameter(graph1), d2 = findDiameter(graph2);

        deque<int> dq1, dq2;
        for (int i=0; i<n+1; i++) {
            if (indegree1[i] == 1) dq1.push_back(i);
        }

        for (int i=0; i<m+1; i++) {
            if (indegree2[i] == 1) dq2.push_back(i);
        }

        int step1 = 0;
        while (dq1.size() > 1) {
            int length = dq1.size();
            if (length > 0) step1++;
            while (length--) {
                int curr = dq1.front();
                dq1.pop_front();
                for (int nxt:graph1[curr]) {
                    indegree1[nxt]--;
                    if (indegree1[nxt] == 1) {
                        dq1.push_back(nxt);
                    }
                }
            }
        }

        int step2 = 0;
        while (dq2.size() > 1) {
            int length = dq2.size();
            if (length > 0) step2++;
            while (length--) {
                int curr = dq2.front();
                dq2.pop_front();
                for (int nxt:graph2[curr]) {
                    indegree2[nxt]--;
                    if (indegree2[nxt] == 1) {
                        dq2.push_back(nxt);
                    }
                }
            }
        }

        return max({step1+step2+1, d1, d2});
    }
};


// Much better! Use two DFS to calculate diameters only
class Solution {
public:
    void getFarthest(vector<vector<int>>& graph, int curr, int parent, int count, int& maxCount, int& farthest) {
        for (int nxt:graph[curr]) {
            if (nxt == parent) continue;
            if (count + 1 > maxCount) {
                maxCount = count+1;
                farthest = nxt;
            }
            getFarthest(graph, nxt, curr, count+1, maxCount, farthest);
        }
    }
    int getDiameter(vector<vector<int>>& graph) {
        int maxCount = 0, farthest = 0;
        getFarthest(graph, 0, -1, 0, maxCount, farthest);
        maxCount = 0;
        getFarthest(graph, farthest, -1, 0, maxCount, farthest);

        return maxCount;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size(), M = edges2.size();
        vector<vector<int>> graph1(N+1), graph2(M+1);
        for (auto &e:edges1) {
            int u = e[0], v = e[1];
            graph1[u].push_back(v);
            graph1[v].push_back(u);
        }

        for (auto &e:edges2) {
            int u = e[0], v = e[1];
            graph2[u].push_back(v);
            graph2[v].push_back(u);
        }

        int diameter1 = getDiameter(graph1);
        int diameter2 = getDiameter(graph2); 


        return max({diameter1, diameter2, 1+(1+diameter1)/2+(1+diameter2)/2});
    }
};