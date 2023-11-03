class Solution {
public:
    int manhattan(vector<int> &a, vector<int> &b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // same shortest distance -> choose smallest worker idx
        // For one worker, many bikes have same distance -> choose smallest bike idx
        vector<pair<int, int>> buckets[2000];
        vector<int> res(workers.size(), -1);
        unordered_set<int> usedWorker;
        unordered_set<int> usedBikes;
        
        for (int i=0; i<workers.size(); i++){
            for (int j=0; j<bikes.size(); j++){
                buckets[manhattan(workers[i], bikes[j])].push_back(pair(i, j));
            }
        }
        
        for (int idx=0; idx<2000; idx++){
            if (buckets[idx].empty()) continue;
            for (auto x:buckets[idx]){
                int i = x.first;
                int j = x.second;
                if (usedWorker.find(i) == usedWorker.end() && usedBikes.find(j) == usedBikes.end()){
                    usedWorker.insert(i);
                    usedBikes.insert(j);
                    res[i] = j;
                    if (usedWorker.size() == workers.size()) return res;
                }
            }
        }
        return res;
    }
};