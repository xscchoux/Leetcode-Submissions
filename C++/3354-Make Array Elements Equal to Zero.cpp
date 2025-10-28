class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int N = nums.size(), res = 0;
        vector<int> preSum(N, 0);
        preSum[0] = nums[0];
        for (int i=1; i<N; i++) {
            preSum[i] = preSum[i-1] + nums[i];
        }

        for (int i=0; i<N; i++) {
            if (nums[i] == 0) {
                int leftSum = (i==0?0:preSum[i-1]);
                int rightSum = (i==N-1?0:preSum[N-1]-preSum[i]);
                if (leftSum == rightSum) {
                    res+=2;
                } else if (leftSum+1 == rightSum || rightSum+1 == leftSum) {
                    res++;
                }
            }
        }

        return res;
    }
};