class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int N = nums.size();
        for (int i=0; i<N; i++) {
            if (i == 0) nums[i] -= k;
            else {
                nums[i] = min(max(nums[i-1]+1, nums[i]-k), nums[i]+k);
            }
        }
        unordered_set<int> s(begin(nums), end(nums));

        return s.size();
    }
};