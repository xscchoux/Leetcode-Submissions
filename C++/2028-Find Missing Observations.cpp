class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int diff = (n+m)*mean - accumulate(rolls.begin(), rolls.end(), 0);
        if (diff < n || diff > 6*n ) return {};

        int q = diff/n, r = diff%n;

        vector<int> res(n);
        for (int i=0; i<n; i++) {
            res[i] = q + (i < r? 1 : 0);
        }

        return res;
    }
};