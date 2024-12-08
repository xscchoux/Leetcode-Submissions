class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    } 
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events), cmp);
        int maxSoFar = 0, res = 0;
        map<int, int> hmap;


        for (auto &e:events) {
            auto it = hmap.lower_bound(e[0]);
            // find the time span with largest end time (smaller than e[0])
            if (it == hmap.begin()) res = max(res, e[2]);
            else {
                it = prev(it);
                res = max(res, e[2] + it->second);
            }
            maxSoFar = max(maxSoFar, e[2]);
            hmap[e[1]] = maxSoFar;
        }

        return res;
    }
};