class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = nums.size();

        vector<pair<int, int>> left(N);
        int running = 0, mxLeft = 0;

        for (int i=0; i<N; i++) {
            running += nums[i];
            if (i >= k) running -= nums[i-k];
            if (i >= k-1) {
                if (mxLeft < running) {
                    mxLeft = running;
                    left[i] = {mxLeft, i-(k-1)};
                } else {
                    left[i] = left[i-1];
                }
                
            }
        }

        vector<pair<int, int>> right(N);
        running = 0;
        int mxRight = 0;

        for (int i=N-1; i>=0; i--) {
            running += nums[i];
            if (i < N-k) running -= nums[i+k];
            if (i <= N-k) {
                if (mxRight <= running) {
                    mxRight = running;
                    right[i] = {mxRight, i};
                } else {
                    right[i] = right[i+1];
                }
            }
        }

        int middle = 0, mxTot = 0;
        vector<int> res(3);
        for (int i=k; i<N-k; i++) {
            middle += nums[i];
            if (i>=2*k) middle -= nums[i-k];
            if (i>=2*k-1) {
                auto leftVal = left[i-k];
                auto rightVal = right[i+1];
                if (leftVal.first + middle + rightVal.first > mxTot) {
                    mxTot = leftVal.first + middle + rightVal.first;
                    res = {leftVal.second, i-(k-1), rightVal.second};
                }
            }
        }
        return res;
    }
};