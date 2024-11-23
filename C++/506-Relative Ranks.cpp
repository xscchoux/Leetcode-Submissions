class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> arr;
        int N = score.size();
        for (int i=0; i<N; i++) {
            arr.push_back({score[i], i});
        }
        sort(begin(arr), end(arr), greater<>());
        vector<string> res(N);
        int cnt = 1;
        for (auto &[_, idx]:arr) {
            if (cnt == 1) {
                res[idx] = "Gold Medal";
            } else if (cnt == 2) {
                res[idx] = "Silver Medal";
            } else if (cnt == 3) {
                res[idx] = "Bronze Medal";
            } else {
                res[idx] = to_string(cnt);
            }
            cnt++;
        }

        return res;
    }
};