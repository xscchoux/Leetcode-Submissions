class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> cnt;
        long long res = 0;
        for (int num:nums2) cnt[num]++;

        for (int num:nums1) {
            if (num%k != 0) continue;
            num = num/k;
            for (int x=1; x<=sqrt(num); x++) {
                if (num%x != 0) continue;
                if (x*x != num) res += cnt[num/x];
                res += cnt[x];
            }
        }
        return res;
    }
};