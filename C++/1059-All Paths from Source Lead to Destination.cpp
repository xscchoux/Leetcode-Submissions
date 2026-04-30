class Solution {
public:
    bool findCycle(int curr, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& srcStack) {
        if (srcStack[curr]) {
            return true;
        }

        if (visited[curr]) {
            return false;
        }
        
        srcStack[curr] = true;
        visited[curr] = true;
        
        for (int nxt:graph[curr]) {
            if (findCycle(nxt, graph, visited, srcStack)) {
                return true;
            }
        }
        srcStack[curr] = false;

        return false;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto &e:edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
        }

        // check if there's a cycle
        // https://www.geeksforgeeks.org/dsa/detect-cycle-in-a-graph/
        vector<bool> visited(n), srcStack(n);
        bool hasCycle = findCycle(source, graph, visited, srcStack);

        if (hasCycle) {
            return false;
        }

        queue<int> q;
        q.push(source);
        vector<bool> seen(n, false);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (graph[curr].empty()) {
                if (curr != destination) return false;
                continue;
            }
            seen[curr] = true;

            for (int nxt:graph[curr]) {
                if (!seen[nxt]) {
                    seen[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        return true;
    }
};