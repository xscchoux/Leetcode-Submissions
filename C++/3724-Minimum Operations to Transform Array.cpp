class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0;
        int lastNum = nums2.back(), closest = INT_MAX;

        for (int i=0; i<nums1.size(); i++) {
            res += abs(nums1[i]-nums2[i]);
            auto [mn, mx] = minmax(nums1[i], nums2[i]);
            if ( mn <= lastNum && mx >= lastNum) {
                closest = 0;
            }
            if (closest > 0) {
                closest = min({closest, abs(lastNum-nums2[i]), abs(lastNum-nums1[i])});
            }
        }

        return res + closest + 1;
    }
};