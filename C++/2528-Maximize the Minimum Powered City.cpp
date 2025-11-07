class Solution {
public:
    int N, k;
    bool isOK(vector<long long>& stations, int r, long long minVal) {
        vector<long long> dp(N+1, 0);
        long long running = 0;
        long long tmp = k;

        for (int i=0; i<N; i++) {
            running += dp[i];
            if (stations[i] + running >= minVal) continue;
            else {
                long long diff = minVal - (stations[i] + running);
                running += diff;
                tmp -= diff;
                if (tmp < 0) return false;
                if (i+r+r+1 < N) {
                    dp[i+r+r+1] -= diff;
                }
                
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        this->N = stations.size();
        this->k = k;
        vector<long long> arr(begin(stations), end(stations));
        vector<long long> preSum(N);
        preSum[0] = arr[0];
        for (int i=1; i<N; i++) {
            preSum[i] = preSum[i-1] + arr[i];
        }

        for (int i=0; i<N; i++) {
            long long leftSum = (i>0?preSum[i-1] - ((i-r-1<0)?0:preSum[max(i-r-1, 0)]):0);
            long long rightSum = (i<N-1?preSum[min(i+r, N-1)]-preSum[i]:0);
            arr[i] += leftSum+rightSum;
        }

        long long  mn = *min_element(begin(arr), end(arr));

        long long left = mn, right=reduce(stations.begin(), stations.end(), 0LL)+k;
        while (left + 1 < right) {
            long long mid = left + (right-left)/2;
            if (isOK(arr, r, mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (isOK(arr, r, right)) {
            return right;
        } else {
            return left;
        }

    }
};