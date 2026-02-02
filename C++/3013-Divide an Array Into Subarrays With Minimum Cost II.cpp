class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int N = nums.size();
        long long res = LLONG_MAX;

        multiset<int> minMs;
        multiset<int, greater<>> maxMs;
        long long maxMsSum = 0;

        // Maintain a sliding window in the index range [i + 1, min(i + dist, n - 1)]
        // In this window, store the smallest k-2 elements in maxMs, and other elements in minMs
        for (int i=2; i <= min(N-1, dist+1); i++) {
            maxMs.insert(nums[i]);
            maxMsSum += nums[i];
            if (maxMs.size() > k-2) {
                int mxVal = *maxMs.begin();
                maxMsSum -= mxVal;
                minMs.insert(mxVal);
                maxMs.erase(maxMs.find(mxVal));
            }
        }

        res = min(res, maxMsSum + nums[0] + nums[1]);

        for (int i1=2; i1<N; i1++) {
            if (N-i1 - 1 < k-2) break;

            // remove nums[i1]
            if (maxMs.contains(nums[i1])) {
                maxMs.erase(maxMs.find(nums[i1]));
                maxMsSum -= nums[i1];
            } else {
                minMs.erase(minMs.find(nums[i1]));
            }

            // add nums[i1+dist]
            if (i1 + dist < N) {
                if (*maxMs.begin() >= nums[i1+dist]) {
                    maxMs.insert(nums[i1+dist]);
                    maxMsSum += nums[i1+dist];
                } else {
                    minMs.insert(nums[i1+dist]);
                }
            }

            // balance the two multisets
            while (maxMs.size() < k-2) {
                int mnVal = *minMs.begin();
                maxMs.insert(mnVal);
                maxMsSum += mnVal;
                minMs.erase(minMs.find(mnVal));
            }
            while (maxMs.size() > k-2) {
                int mxVal = *maxMs.begin();
                minMs.insert(mxVal);
                maxMs.erase(maxMs.find(mxVal));
                maxMsSum -= mxVal;
            }
            res = min(res, maxMsSum + nums[0] + nums[i1]);
        }
        
        return res;
    }
};