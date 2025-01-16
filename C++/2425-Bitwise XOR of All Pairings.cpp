class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size(), N2 = nums2.size();
        int res = 0;
        if (N2%2) {
            for (int num:nums1) {
                res ^= num;
            }
        }
        if (N1%2) {
            for (int num:nums2) {
                res ^= num;
            }
        }
        return res;
    }
};