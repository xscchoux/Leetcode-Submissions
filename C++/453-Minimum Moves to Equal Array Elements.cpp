class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long tot = 0;
        int N = nums.size(), mx = INT_MAX;
        for (int i=0; i<N; i++) {
            tot += nums[i];
            mx = min(mx, nums[i]);
        }

        return tot - mx*N;

    }
};