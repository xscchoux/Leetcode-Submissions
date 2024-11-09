class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for (auto p:prerequisites) {
            int u = p[0], v = p[1];
            graph[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        for (int i=0; i<numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int cnt = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cnt++;
            for (int nxt:graph[curr]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) q.push(nxt);
            }
        }

        return cnt == numCourses;
    }
};