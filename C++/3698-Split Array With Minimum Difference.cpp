class Solution {
public:
    long long splitArray(vector<int>& nums) {
        vector<int> left, right;
        long long res = LLONG_MAX;
        int N = nums.size();
        
        // left part increasing and right part decreasing
        left.push_back(nums[0]);
        int idx = 0;
        for (idx=1; idx<nums.size(); idx++) {
            if (nums[idx] > nums[idx-1]) {
                left.push_back(nums[idx]);
            } else {
                break;
            }
        }
        if (idx < N) {
            right.push_back(nums[idx]);
            for (int idx2 = idx+1; idx2 < nums.size(); idx2++) {
                if (nums[idx2] < nums[idx2-1]) {
                    right.push_back(nums[idx2]);
                } else {
                    break;
                }
            }
        }

        if (left.size() + right.size() == N) {
            if (!right.empty()) {
                 res = min(res, abs(accumulate(begin(left), end(left), 0LL) - accumulate(begin(right), end(right), 0LL)) );
            }
            if (left.size() >= 2) {
                res = min(res, abs(accumulate(begin(left), end(left), 0LL) - accumulate(begin(right), end(right), 0LL) - 2*left.back()));
            }
        }

        return res==LLONG_MAX?-1:res;
    }
};