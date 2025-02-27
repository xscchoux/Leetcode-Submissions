class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        map<pair<int, int>, int> dp;  // {previous index, current index} : length
        unordered_map<int, int> pos;
        int N = arr.size(), res = 0;

        for (int i=0; i<N; i++) {
            for (int j=0; j<i; j++) {
                int prev = arr[i] - arr[j];
                if (pos.contains(prev) && pos[prev] < j) {
                    if (!dp.contains({pos[prev], j})) dp[{pos[prev], j}] = 2;
                    dp[{j, i}] = dp[{pos[prev], j}] + 1;
                    res = max(res, dp[{j, i}]);
                }
            }
            pos[arr[i]] = i;
        }

        return res>=3?res:0;
    }
};