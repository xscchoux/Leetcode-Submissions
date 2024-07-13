class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int N = fronts.size();
        int res = INT_MAX;
        unordered_set<int> banned;

        for (int i=0; i<N; i++) {
            if (fronts[i] == backs[i]) banned.insert(fronts[i]);
        }

        for (int i=0; i<N; i++) {
            if (fronts[i] != backs[i]) {
                if (!banned.contains(fronts[i])) res = min(res, fronts[i]);
                if (!banned.contains(backs[i])) res = min(res, backs[i]);
            }
        }
        return (res < INT_MAX)?res:0;
    }
};