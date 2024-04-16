class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        // https://github.com/wisdompeak/LeetCode/tree/master/Math/3102.Minimize-Manhattan-Distances
        vector<multiset<int>> mset(4);
        int res = INT_MAX;
        for (auto &point:points) {
            int u = point[0], v = point[1];
            mset[0].insert(u+v);
            mset[1].insert(u-v);
            // mset[2].insert(-u+v);  // we only need u+v and u-v
            // mset[3].insert(-u-v);
        }
        
        for (auto &point:points) {
            int u = point[0], v = point[1];
            mset[0].erase(mset[0].find(u+v));
            mset[1].erase(mset[1].find(u-v));
            // mset[2].erase(mset[2].find(-u+v));
            // mset[3].erase(mset[3].find(-u-v));
            
            int curr = 0;
            
            curr = max(curr, *prev(mset[0].end()) - *mset[0].begin());
            curr = max(curr, *prev(mset[1].end()) - *mset[1].begin());
            // curr = max(curr, *prev(mset[2].end()) - *mset[2].begin());
            // curr = max(curr, *prev(mset[3].end()) - *mset[3].begin());
            
            res = min(curr, res);
            
            mset[0].insert(u+v);
            mset[1].insert(u-v);
            // mset[2].insert(-u+v);
            // mset[3].insert(-u-v);
        }        
        
        return res;
    }
};