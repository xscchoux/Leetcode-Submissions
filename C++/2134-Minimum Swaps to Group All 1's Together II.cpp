class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int oneCnt = accumulate(nums.begin(), nums.end(), 0);
        int curr = 0, N = nums.size();
        nums.resize(2*N-1);

        for (int i=N; i<2*N-1; i++) {
            nums[i] = nums[i-N];
        }

        for (int i=0; i<oneCnt; i++) {
            curr += nums[i];
        }
        int res = oneCnt - curr;
        for (int i=oneCnt; i<2*N-1; i++) {
            curr += nums[i];
            curr -= nums[i-oneCnt];
            res = min(res, oneCnt-curr);
        }

        return res;
    }
};