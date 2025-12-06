class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int N = technique1.size();
        long long res = 0;
        vector<pair<int, int>> arr;
        for (int i=0; i<N; i++) {
            arr.push_back({technique1[i] - technique2[i], i});
        }

        sort(begin(arr), end(arr), greater<>());

        for (int i=0; i<N; i++) {
            int idx = arr[i].second;
            if (i < k) {
                res += technique1[idx];
            } else {
                res += arr[i].first>=0?technique1[idx]:technique2[idx];
            }
        }

        return res;
    }
};