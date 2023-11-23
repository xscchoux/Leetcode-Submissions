class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int first = -1e4, second = -1e4;
        for (vector<int> &a:arrays){
            if (a[a.size()-1] > first){
                second = first;
                first = a[a.size()-1];
            } else if (a[a.size()-1] > second){
                second = a[a.size()-1];
            }
        }
        
        int res = 0;
        for (auto &a:arrays){
            if (a[a.size()-1] == first){
                res = max(res, second - a[0]);
            } else {
                res = max(res, first - a[0]);
            }
        }
        return res;
    }
};