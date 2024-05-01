// binary search
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();

        for (int i=0; i<N; i++) nums1[i] = nums1[i] - nums2[i];

        sort(nums1.begin(), nums1.end());

        long long res = 0;
        for (int i=1; i<N; i++) {
            if (nums1[i] > 0) {
                res += i - (lower_bound(nums1.begin(), nums1.begin()+i, -nums1[i] + 1) - nums1.begin());
            }
        }

        return res;
    }
};

// two pointers
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();

        for (int i=0; i<N; i++) nums1[i] = nums1[i] - nums2[i];

        sort(nums1.begin(), nums1.end());


        long long res = 0;
        int left = 0, right = N-1;
        
        while (left < right) {
            if (nums1[right]+nums1[left] > 0) {
                res += right-left;
                right--;
            } else {
                left++;
            }
        }
        return res;
    }
};