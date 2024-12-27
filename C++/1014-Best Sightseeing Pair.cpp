class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int N = values.size(), res = 0;
        int imax = values[0];
        for (int i=1; i<N; i++) {
            res = max(res, values[i]-i+imax);
            imax = max(imax, values[i]+i);
        }

        return res;
    }
};