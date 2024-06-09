class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k, 0);
        cnt[0] = 1;
        int curr = 0;
        int res = 0;

        for (int num:nums) {
            curr = (curr + num%k + k)%k;   // a = (a/b)*b + a%b, a%b = a - (a/b)*b, so sometimes a%b gives negative results.
            res += cnt[curr];
            cnt[curr]++;
        }

        return res;
    }
};