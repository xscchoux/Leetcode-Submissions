class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int original = 0, N = nums.size(), mx = *max_element(begin(nums), end(nums));
        for (int i=0; i<N; i++) {
            if (nums[i] == k) original++;
        }

        // c: number to be converted to k
        // Kadane algorithm: num == k -> -1, nums == c -> +1, find the maximum subarray sum
        int globalMax = INT_MIN;
        for (int c=1; c<=mx; c++) {
            if (c == k) continue;
            int running = 0;
            for (int i=0; i<N; i++) {
                if (nums[i] == c) running++;
                if (nums[i] == k) running--;
                globalMax = max(globalMax, running);
                if (running < 0) running = 0;
            }
        }
        
        return max(original, globalMax + original);
    }
};