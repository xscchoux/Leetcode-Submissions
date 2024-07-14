class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int vCut = 1, hCut = 1;
        vector<pair<int, char>> cuts;
        long long res = 0;
        for (int i=0; i<horizontalCut.size(); i++) {
            cuts.push_back({horizontalCut[i], 'H'});
        }
        for (int i=0; i<verticalCut.size(); i++) {
            cuts.push_back({verticalCut[i], 'V'});
        }

        sort(cuts.begin(), cuts.end(), greater<>());

        for (int i=0; i<cuts.size(); i++) {
            if (cuts[i].second == 'H') {
                res += (cuts[i].first)*(long long)hCut;
                vCut++;
            } else {
                res += (cuts[i].first)*(long long)vCut;
                hCut++;                
            }
        }
        return res;
    }
};