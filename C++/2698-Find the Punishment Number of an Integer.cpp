// O(N*2^(log10(N)))
class Solution {
public:
    bool check(int num, int target) {
        if (num == target) return true;

        int d = 10, digits = log10(num);

        for (int i=1; i<=digits; i++) {
            int q = num/d, r = num%d;
            if (r >= target) break;
            if (check(q, target-r)) {
                return true;
            }
            d *= 10;
        }

        return false;
    }
    int punishmentNumber(int n) {
        int res = 0;

        for (int i=1; i<=n; i++) {
            if (check(i*i, i)) {
                res += i*i;
            }
        }

        return res;
    }
};