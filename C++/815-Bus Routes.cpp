class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        unordered_map<int, vector<int>> group;
        for (int i=0; i<routes.size(); i++){
            for (int x:routes[i]){
                group[x].push_back(i);
            }
        }
        
        queue<int> q;
        q.push(source);
        unordered_set<int> visitedGroup;
        unordered_set<int> visitedStop;
        visitedStop.insert(source);
        
        int step = 0;
        
        while (!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                int curr = q.front(); q.pop();
                if (curr == target) return step;
                for (int groupIdx:group[curr]){
                    if (!visitedGroup.count(groupIdx)){
                        visitedGroup.insert(groupIdx);
                        for (int stop:routes[groupIdx]){
                            if (!visitedStop.count(stop)){
                                visitedStop.insert(stop);
                                q.push(stop);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};