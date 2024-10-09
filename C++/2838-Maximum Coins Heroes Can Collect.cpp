using LL = long long;
class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        vector<pair<int, int>> arr;
        int N = monsters.size();
        for (int i=0; i<N; i++) {
            arr.push_back({monsters[i], coins[i]});
        }
        sort(arr.begin(), arr.end());
        vector<LL> preSum(N);
        preSum[0] = arr[0].second;
        for (int i=1; i<N; i++) {
            preSum[i] = preSum[i-1] + arr[i].second;
        }
        
        vector<LL> res;
        for (int i=0; i<heroes.size(); i++) {
            auto it = upper_bound(arr.begin(), arr.end(), heroes[i], [](int val, const pair<int, int>& ele) {
                return val < ele.first;
            });
            if (it == arr.begin()) {
                res.push_back(0);
                continue;
            }
            int idx = (it - arr.begin()) - 1;
            res.push_back(preSum[idx]);
        }

        return res;
    }
};