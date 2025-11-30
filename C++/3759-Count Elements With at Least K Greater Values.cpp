// naive approach
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            int idx = upper_bound(begin(nums), end(nums), nums[i]) - begin(nums);
            if (nums.size() - idx >= k) {
                res++;
            } else {
                break;
            }
        }
        return res;
    }
};


// Use nth_element, much faster
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int N = nums.size(), res = 0;
        if (k == 0) return N;  // We need this cause we cannot have nums[N]

        nth_element(begin(nums), begin(nums)+N-k, end(nums));  // O(N)

        for (int num:nums) {
            res += (num < nums[N-k]);
        }

        return res;
    }
};