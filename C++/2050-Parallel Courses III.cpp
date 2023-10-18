class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree = vector(n, 0);
        
        for (vector<int> &edge:relations){
            int s = edge[0]-1, e = edge[1]-1;
            graph[s].push_back(e);
            indegree[e]++;
        }
        
        queue<int> queue;
        vector<int> maxTime = vector(n, 0); // end time the course completes
        for (int i=0; i<n; i++){
            if (indegree[i] == 0){
                maxTime[i] = time[i];
                queue.push(i);
            }
        }
        
        while (!queue.empty()){
            int curr = queue.front();
            queue.pop();
            for (int nxt:graph[curr]){
                maxTime[nxt] = max(maxTime[nxt], maxTime[curr] + time[nxt]);
                indegree[nxt]--;
                if (indegree[nxt] == 0){
                    queue.push(nxt);
                }
            }
        }
        
        return *max_element(maxTime.begin(), maxTime.end());
    }
};