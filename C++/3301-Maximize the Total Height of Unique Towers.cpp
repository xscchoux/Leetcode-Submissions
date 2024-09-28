class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        long long res = 0;
        sort(maximumHeight.begin(), maximumHeight.end(), greater<>());
        int N = maximumHeight.size();
        for (int i=0; i<N; i++) {
            if (i > 0 && maximumHeight[i] >= maximumHeight[i-1]) {
                maximumHeight[i] = maximumHeight[i-1]-1;
                if (maximumHeight[i] <= 0) return -1;
                res += maximumHeight[i];
            } else {
                res += maximumHeight[i];
            }
        }

        return res;
    }
};