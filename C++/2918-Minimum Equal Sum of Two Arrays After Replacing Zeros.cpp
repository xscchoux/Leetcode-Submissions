class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeroCnt1 = 0, zeroCnt2 = 0;
        long long tot1 = 0, tot2 = 0;

        for (int i=0; i<nums1.size(); i++) {
            if (nums1[i] == 0) zeroCnt1++;
            tot1 += nums1[i];
        }

        for (int i=0; i<nums2.size(); i++) {
            if (nums2[i] == 0) zeroCnt2++;
            tot2 += nums2[i];
        }

        if (zeroCnt1 == 0 && zeroCnt2 == 0) {
            return tot1 == tot2? tot1:-1;
        } else if (zeroCnt1 == 0) {
            return tot1 < tot2 + zeroCnt2?-1:tot1;
        } else if (zeroCnt2 == 0) {
            return tot2 < tot1 + zeroCnt1?-1:tot2;            
        } else {
            return max(tot1 + zeroCnt1, tot2 + zeroCnt2);
        }
    }
};