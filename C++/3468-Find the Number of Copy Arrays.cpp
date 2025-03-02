class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int lower = INT_MIN, upper = INT_MAX, N = original.size();
        for (int i=0; i<N; i++) {
            lower = max(lower, bounds[i][0] - original[i]);
            upper = min(upper, bounds[i][1] - original[i]);
            if (upper < lower) return 0;
        }

        return upper-lower+1;
    }
};