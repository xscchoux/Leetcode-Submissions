class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2), greater<>());
        int res = 0;
        for (int i=0; i<nums1.size(); i++) {
            res += nums1[i]*nums2[i];
        }

        return res;
    }
};