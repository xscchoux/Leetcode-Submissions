class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> s;
        for (auto &point:points){
            s.insert(point[0]);
        }
        int res = 0;
        for (auto it = next(s.begin()); it != s.end(); it++){
            res = max(res, *it - *prev(it));
        }
        
        return res;
    }
};