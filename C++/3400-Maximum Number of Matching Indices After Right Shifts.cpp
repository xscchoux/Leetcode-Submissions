class Solution {
public:
    int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size(), N2 = nums2.size();
        int res = 0;
        for (int i=0; i<N1; i++) {
            int idx1 = i, tmp = 0;
            for (int j=0; j<N2; j++) {
                if (nums1[idx1%N1] == nums2[j]) {
                    tmp++;
                }
                idx1++;
            }
            res = max(res, tmp);
        }
        return res;
    }
};