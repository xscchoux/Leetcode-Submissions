using LL = long long;
class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        // For two enemies,
        // if we kill enemy 0 then enemy 1, the cost is t0d0 + t1d1 + t0d1
        // if we kill enemy 1 then enemy 2, the cost is t0d0 + t1d1 + t1d0

        // So we only need to compare t0d1 and t1d0

        int N = damage.size();
        vector<int> time;
        for (int i=0; i<N; i++) {
            time.push_back((health[i]+power-1)/power);
        }

        vector<int> indices(N);
        iota(indices.begin(), indices.end(), 0);  // Fill indices with 0, 1, 2, ...

        // Sort indices based on the corresponding damage values and then by `t` if damage is equal
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return time[a]*damage[b] < time[b]*damage[a];
        });

        LL res = 0, totDamage = accumulate(damage.begin(), damage.end(), 0);
        for (int i=0; i<N; i++) {
            res += totDamage*time[indices[i]];
            totDamage -= damage[indices[i]];
        }

        return res;
    }
};