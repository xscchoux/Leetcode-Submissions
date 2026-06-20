class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(begin(restrictions), end(restrictions), [] (auto &a, auto &b) {
            return a[0] < b[0];
        });

        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n-1});
        }
        
        int sz = restrictions.size();

        // left to right (restrictions[i][1] is the max height we can reach if we travel from left to right)
        for (int i = 1; i < sz; i++) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
        }

        // right to left (restrictions[i][1] is the max height we can reach if we travel both from left to right and right to left)
        for (int i = sz-2; i>=0; i--) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }

        // Let the peak height between restrictions[i][1] and restrictions[j][1] be best(i, j)
        // (best(i, j) - restrictions[i][1]) + (best(i, j) - restrictions[j][1]) <= j-i
        // =>  best(i, j) = ((j-i) + restrictions[i][1] + restrictions[j][1])/2
        int res = 0;
        for (int i=0; i<sz-1; i++) {
            res = max(res, (restrictions[i+1][0] - restrictions[i][0] + restrictions[i][1] + restrictions[i+1][1])/2 );
        }

        return res;
    }
};