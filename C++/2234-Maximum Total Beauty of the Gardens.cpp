using LL = long long;
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int N = flowers.size();
        sort(begin(flowers), end(flowers));
        vector<LL> preSum(N, 0);
        preSum[0] = flowers[0];
        for (int i=1; i<N; i++) {
            preSum[i] = preSum[i-1] + flowers[i];
        }

        LL res = 0;
        // the leftmost index where flowers[index] >= target
        int completeIdx = lower_bound(begin(flowers), end(flowers), target) - begin(flowers);

        for (int idx=completeIdx; idx>=0; idx--) {
            if (idx < N) newFlowers -= max(target-flowers[idx], 0);
            if (newFlowers < 0) break;

            if (idx == 0) {   // edge case: when idx == 0, don't binary search (or right will be -1)
                res = max(res, (LL)N*full);
                return res;
            }

            int left = 0, right = idx-1;
            while (left+1<right) {
                int mid = left + (right-left)/2;
                if ( (LL)flowers[mid]*(mid+1)-preSum[mid] <= newFlowers ) {
                    left = mid;
                } else {
                    right = mid;
                }
            }

            int lastIdx;
            if ((LL)flowers[right]*(right+1)-preSum[right] <= newFlowers) {
                lastIdx = right;
            } else {
                lastIdx = left;
            }

            LL partialVal = min(flowers[lastIdx] + (newFlowers-((LL)flowers[lastIdx]*(lastIdx+1)-preSum[lastIdx]))/(lastIdx+1), (LL)target-1);  // note that for incomplete gardens, the maximum number of flowers is target-1 

            res = max(res, (LL)(N-idx)*full + partialVal*partial );
        }
        return res;
    }
};