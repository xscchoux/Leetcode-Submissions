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


// use hash map + priority_queue
using PII = pair<int, int>;
class TaskManager {
private:
    unordered_map<int, PII> taskHmap; // taskId: {priority, userId}
    priority_queue<PII> pq;           // {priority, taskId}
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &task:tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskHmap[taskId] = make_pair(priority, userId);
            pq.push({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskHmap[taskId] = {priority, userId};
        pq.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        taskHmap[taskId].first = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        taskHmap.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top();
            pq.pop();
            if (taskHmap.contains(taskId) && priority == taskHmap[taskId].first) {
                int userId = taskHmap[taskId].second;
                taskHmap.erase(taskId);
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
