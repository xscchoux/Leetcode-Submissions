class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int N = nums.size();
        long long tot = accumulate(begin(nums), end(nums), 0LL);
        long long halfSum = accumulate(begin(nums), begin(nums) + N/2, 0LL);

        int res = 0;
        if (halfSum > tot - halfSum) res++;

        for (int i=N/2; i<N+N/2-1; i++) {
            halfSum += nums[i%N];
            halfSum -= nums[(i-N/2)%N];
            if (halfSum > tot - halfSum) res++;
        }

        return res;

    }
};