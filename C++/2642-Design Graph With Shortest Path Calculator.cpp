class Graph {
public:
    unordered_map<int, vector<pair<int, int>>> graph;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for (vector<int>& edge:edges){
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // distance, node
        unordered_set<int> visited;
        pq.push({0, node1});
        
        while (!pq.empty()){
            auto [dist, curr] = pq.top();
            if (curr == node2) return dist;
            pq.pop();
            if (visited.count(curr)) continue;
            visited.insert(curr);
            for (auto &[nxt, weight]:graph[curr]){
                if (!visited.count(nxt)){
                    pq.push({dist+weight, nxt});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */