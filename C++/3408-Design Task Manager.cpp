class TaskManager {
public:
    unordered_map<int, pair<int, int>> triple; // taskId:(priority, userId)
    map<int, set<int, greater<>>, greater<>> p;  // priority:taskId
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &task:tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            triple[taskId] = make_pair(priority, userId);
            p[priority].insert(taskId);
        }        
    }
    
    void add(int userId, int taskId, int priority) {
        triple[taskId] = make_pair(priority, userId);
        p[priority].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        int currPriority = triple[taskId].first;
        triple[taskId].first = newPriority;

        p[currPriority].erase(taskId);
        if (p[currPriority].empty()) p.erase(currPriority);
        p[newPriority].insert(taskId);
    }
    
    void rmv(int taskId) {
        int currPriority = triple[taskId].first;
        triple.erase(taskId);
        p[currPriority].erase(taskId);
        if (p[currPriority].empty()) p.erase(currPriority);
    }
    
    int execTop() {
        if (p.empty()) return -1;
        int highestP = begin(p)->first;
        if (p[highestP].empty()) return -1;
        int taskId = *begin(p)->second.begin();

        int userId = triple[taskId].second;

        // remove
        triple.erase(taskId);
        p[highestP].erase(taskId);
        if (p[highestP].empty()) p.erase(highestP);
        
        return userId;
    }
};