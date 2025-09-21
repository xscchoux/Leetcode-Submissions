class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx = *max_element(begin(nums), end(nums)), mn = *min_element(begin(nums), end(nums));

        return (long long)k*(mx-mn);
    }
};