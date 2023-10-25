class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> graph;
        int N = quiet.size();
        vector<int> indegree = vector(N, 0);
        
        for (vector<int>& pair:richer){
            int u = pair[0];
            int v = pair[1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        deque<int> queue;
        vector<int> index;
        for (int i=0; i<indegree.size(); i++){
            if (indegree[i] == 0) queue.push_back(i);
            index.push_back(i);
        }
        
        while (!queue.empty()){
            int size = queue.size();
            for (int i=0; i<size;i++){
                int curr = queue.front();
                queue.pop_front();
                
                for (int nxt:graph[curr]){
                    if (quiet[curr] < quiet[nxt]){
                        quiet[nxt] = quiet[curr];
                        index[nxt] = index[curr];
                    }
                    indegree[nxt]--;
                    if (indegree[nxt] == 0) queue.push_back(nxt);
                }
            }
        }
        return index;
    }
};