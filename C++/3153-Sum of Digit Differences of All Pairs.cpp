using LL = long long;
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        LL res = 0;
        int digit = to_string(nums[0]).size();
        for (int i=0; i<digit; i++) {
            vector<int> cnt(10);
            int base = pow(10, i);
            for (int num:nums) {
                int currVal = (num/base)%10;
                for (int j=0; j<10; j++) {
                    if (currVal != j) res += cnt[j];
                }
                cnt[currVal]++;
            }
        }
        return res;
    }
};