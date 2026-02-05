class RideSharingSystem {
public:
    set<pair<int, int>> riderSet, driverSet;
    unordered_map<int, int> riderMap;
    int t = 0;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riderMap[riderId] = t;
        riderSet.insert({t++, riderId});
    }
    
    void addDriver(int driverId) {
        driverSet.insert({t++, driverId});
    }
    
    vector<int> matchDriverWithRider() {
        if (riderSet.empty() || driverSet.empty()) return {-1, -1};
        vector<int> res;
        
        res.push_back(driverSet.begin()->second);
        driverSet.erase(driverSet.begin());

        riderMap.erase(riderSet.begin()->second);
        res.push_back(riderSet.begin()->second);
        riderSet.erase(riderSet.begin());
        return res;   
    }
    
    void cancelRider(int riderId) {
        if (!riderMap.contains(riderId)) return;
        int time = riderMap[riderId];
        riderMap.erase(riderId);
        riderSet.erase({time, riderId});
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */