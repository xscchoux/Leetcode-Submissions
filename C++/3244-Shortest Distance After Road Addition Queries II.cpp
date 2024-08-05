class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> s;
        for (int i=0; i<n; i++) s.insert(i);
        vector<int> arr;
        
        for (auto &q:queries) {
            int start = q[0], end = q[1];
            auto itlow = s.upper_bound(start);
            auto itup = s.lower_bound(end);
            s.erase(itlow, itup);
            arr.push_back(s.size()-1);
        }

        return arr;
    }
};