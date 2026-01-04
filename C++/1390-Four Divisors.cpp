class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int num:nums) {
            int cnt = 0, d = 0;;
            for (int i=1; i*i<=num; i++) {
                if (num%i == 0) {
                    cnt += 2;
                    d += (i + num/i);
                    if (i*i == num) cnt--, d-=i;
                }
            }
            if (cnt == 4) {
                res += d;
            }
        }
        return res;
    }
};