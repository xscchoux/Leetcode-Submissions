class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int N = capacity.size();

        vector<long long> preSum(N, 0);
        preSum[0] = capacity[0];
        for (int i=1; i<N; i++) {
            preSum[i] = preSum[i-1] + capacity[i];
        }

        map<pair<int, long long>, int> cnt;
        long long res = 0;


        for (int i=0; i<N; i++) {
            if (i>=2) {
                cnt[{capacity[i-2], preSum[i-2]}]++;
            }
            if (cnt.contains({capacity[i], preSum[i]-2*capacity[i]})) {
                res += cnt[{capacity[i], preSum[i]-2*capacity[i]}];
            }
        }

        return res;
    }
};


// a little faster using nested map
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int N = capacity.size();

        vector<long long> preSum(N, 0);
        preSum[0] = capacity[0];
        for (int i=1; i<N; i++) {
            preSum[i] = preSum[i-1] + capacity[i];
        }

        unordered_map<int, unordered_map<long long, int>> cnt;
        long long res = 0;


        for (int i=0; i<N; i++) {
            if (i>=2) {
                cnt[capacity[i-2]][preSum[i-2]]++;
            }
            if (cnt.count(capacity[i]) && cnt[capacity[i]].count(preSum[i]-2*capacity[i])) {
                res += cnt[capacity[i]][preSum[i]-2*capacity[i]];
            }
        }

        return res;
    }
};