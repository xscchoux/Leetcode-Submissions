class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size(), n = N/3;
        multiset<int> leftMS, rightMS;
        long long res = LLONG_MAX;
        vector<long long> prefixSum(N, 0);

        long long pre = 0;
        for (int i=0; i<N-n; i++) {
            leftMS.insert(nums[i]);
            pre += nums[i];
            if (i >= n) {
                int leftVal = *leftMS.rbegin();
                leftMS.erase(leftMS.find(leftVal));
                pre -= leftVal;
            }
            if (i >= n-1) {
                prefixSum[i] = pre;
            }
        }

        long long suf = 0;
        for (int i=N-1; i>=n; i--) {
            rightMS.insert(nums[i]);
            suf += nums[i];
            if (i < N-n) {
                int rightVal = *rightMS.begin();
                rightMS.erase(rightMS.find(rightVal));
                suf -= rightVal;
            }
            if (i <= N-n) {
                res = min(res, prefixSum[i-1] - suf);
            }
        }


        return res;
    }
};

// priority queue, much faster
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size(), n = N/3;
        priority_queue<int> leftPQ;
        priority_queue<int, vector<int>, greater<>> rightPQ;
        long long res = LLONG_MAX;
        vector<long long> prefixSum(N, 0);

        long long pre = 0;
        for (int i=0; i<N-n; i++) {
            leftPQ.push(nums[i]);
            pre += nums[i];
            if (i >= n) {
                int leftVal = leftPQ.top();
                leftPQ.pop();
                pre -= leftVal;
            }
            if (i >= n-1) {
                prefixSum[i] = pre;
            }
        }

        long long suf = 0;
        for (int i=N-1; i>=n; i--) {
            rightPQ.push(nums[i]);
            suf += nums[i];
            if (i < N-n) {
                int rightVal = rightPQ.top();
                rightPQ.pop();
                suf -= rightVal;
            }
            if (i <= N-n) {
                res = min(res, prefixSum[i-1] - suf);
            }
        }

        return res;
    }
};