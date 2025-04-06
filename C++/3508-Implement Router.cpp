class Router {
public:
    int mLimit;
    queue<array<int, 3>> q;
    set<array<int, 3>> packets;
    unordered_map<int, deque<int>> destMap;

    Router(int memoryLimit) {
        mLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        array<int, 3> curr = {timestamp, source, destination};
        if (packets.contains(curr)) return false;
        q.push(curr);
        packets.insert(curr);
        destMap[destination].push_back(timestamp);

        if (q.size() > mLimit) {
            forwardPacket();
        }

        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto [timestamp, source, destination] = q.front();
        q.pop();

        array<int, 3> curr = {timestamp, source, destination};
        packets.erase(curr);
        destMap[destination].pop_front();

        return {source, destination, timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &dq = destMap[destination];
        int res = upper_bound(begin(dq), end(dq), endTime) - lower_bound(begin(dq), end(dq), startTime);

        return res;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */