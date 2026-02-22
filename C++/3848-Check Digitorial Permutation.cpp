long long fac[10] = {1};

int fillVector = []() {
    for (int i=1; i<=9; i++) {
        fac[i] = fac[i-1]*i;
    }
    return 0;
}();


class Solution {
public:
    bool isDigitorialPermutation(int n) {
        unordered_map<int, int> cnt;
        long long facSum = 0;

        while (n > 0) {
            int c = n%10;
            cnt[c]++;
            facSum += fac[c];
            n = n/10;
        }
        
        while (facSum > 0) {
            int c = facSum%10;
            facSum = facSum/10;
            if (cnt[c] > 0) {
                cnt[c]--;
                if (cnt[c] == 0) {
                    cnt.erase(c);
                }
            } else {
                return false;
            }
        }


        return cnt.empty();
    }
};