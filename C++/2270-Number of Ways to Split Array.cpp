class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int N = nums.size();
        long long running = 0, tot = accumulate(begin(nums), end(nums), 0LL);
        int res = 0;
        for (int i=0; i<N-1; i++) {
            running += nums[i];
            if (running >= tot-running) res++;
        }
        return res;
    }
};