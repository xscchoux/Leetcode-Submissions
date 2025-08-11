class Solution {
public:
    int kMod = 1e9+7;
    long long powWithMod(long long a, long long b, int kMod) {
        a %= kMod;
        long long res = 1;

        while(b) {
            if (b&1) res=(res*a)%kMod;
            a=(a*a)%kMod;
            b>>=1;
        }

        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i=30; i>=0; i--) {
            if (n >= (1<<i)) {
                n -= (1<<i);
                powers.push_back(i);
            }
        }

        reverse(begin(powers), end(powers));

        vector<int> preProduct = {0};
        for (int i=0; i<powers.size(); i++) {
            preProduct.push_back(preProduct.back()+powers[i]);
        }

        vector<int> res;
        for (auto &q:queries) {
            res.push_back(powWithMod(2, preProduct[q[1]+1] - preProduct[q[0]], kMod));
        }

        return res;
    }
};