class Solution {
public:
    int N;
    // check elements down to nums[i] - 2*k to the left. Not necessarily centered at a number given in nums
    int case2(vector<int>& nums, int k, int numOperations) {
        int res = 0;
        for (int i=0, left=0; i<N; i++) {
            while (nums[i]-nums[left] > 2*k) {
                left++;
            }
            res = max(res, min(numOperations, i-left+1));
        }

        return res;
    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        N = nums.size();
        int res = 0;
        vector<int> left(N), right(N);
        unordered_map<int, int> cnt;
        for (int num:nums) cnt[num]++;
        sort(begin(nums), end(nums));

        // case1
        for (int i=0, l=0; i<N; i++) {
            while (nums[i] - nums[l] > k) {
                l++;
            }
            left[i] = l;
        }

        for (int i=N-1, r=N-1; i>=0; i--) {
            while (nums[r] - nums[i] > k) {
                r--;
            }
            right[i] = r;
        }

        // case 1, center at nums[i] and check elements up to nums[i]+k to the right and nums[i]-k to the left
        for (int i=0; i<N; i++) {
            res = max(res, cnt[nums[i]] + min(numOperations, right[i]-left[i]+1-cnt[nums[i]]));
        }

         // case 2, start with nums[i] and check elements down to nums[i]-2k to the left
        res = max(res, case2(nums, k, numOperations));

        return res;
    }
};