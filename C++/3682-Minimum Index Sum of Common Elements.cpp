class Solution {
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        unordered_map<int, int> hmap2;
        int res = INT_MAX;
        for (int i=0; i<N; i++) {
            if (!hmap2.count(nums2[i])) hmap2[nums2[i]] = i; 
        }

        for (int i=0; i<N; i++) {
            if (hmap2.count(nums1[i])) {
                res = min(res, i + hmap2[nums1[i]]);
            }
        }

        return res<INT_MAX?res:-1;
    }
};