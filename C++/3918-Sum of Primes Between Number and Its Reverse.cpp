const int MAX_N = 1000;
vector<bool> is_prime(MAX_N + 1, true);

int fillVector = []() {
     // is_prime[i] == true means i is prime
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= MAX_N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return 0;
}();


class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int reverseN = 0, tmp = n, res = 0;
        while (tmp > 0) {
            reverseN = reverseN*10 + tmp%10;
            tmp /= 10;
        }

        auto [mn, mx] = minmax(n, reverseN);

        for (int i=mn; i<=mx; i++) {
            if (is_prime[i]) {
                res += i;
            }
        }

        return res;
    }
};