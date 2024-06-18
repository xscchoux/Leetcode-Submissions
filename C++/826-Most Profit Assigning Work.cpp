class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> arr;
        int N = difficulty.size();
        map<int, int> mp;

        for (int i=0; i<N; i++) arr.push_back({difficulty[i], profit[i]});

        sort(arr.begin(), arr.end());

        int maxVal = 0;
        for (int i=0; i<N; i++) {
            maxVal = max(maxVal, arr[i].second);
            mp[arr[i].first] = maxVal;
        }

        int res = 0, currMax = 0;
        for (int i=0; i<worker.size(); i++) {
            auto it = mp.upper_bound(worker[i]);
            if (it != mp.begin()) {
                it--;
                res += it->second;
            }
        }
        return res;
    }
};