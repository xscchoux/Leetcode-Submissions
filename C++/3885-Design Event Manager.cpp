class EventManager {
public:
    // {eventId: priority}
    // {priority1:{id1, id2, ...}, ...}
    unordered_map<int, int> id2priority;
    map<int, set<int>, greater<>> pMap;
    EventManager(vector<vector<int>>& events) {
        for (auto &event:events) {
            int id = event[0], p = event[1];
            id2priority[id] = p;
            pMap[p].insert(id);
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldPriority = id2priority[eventId];
        pMap[oldPriority].erase(eventId);
        if (pMap[oldPriority].empty()) pMap.erase(oldPriority);

        id2priority[eventId] = newPriority;
        pMap[newPriority].insert(eventId);
    }
    
    int pollHighest() {
        if (pMap.empty()) return -1;
        auto &rset = pMap.begin()->second;
        int id = *rset.begin();

        rset.erase(id);
        if (rset.empty()) {
            pMap.erase(pMap.begin());
        }
        return id;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */