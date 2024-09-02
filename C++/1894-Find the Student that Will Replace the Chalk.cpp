using LL = long long;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        LL tot = accumulate(chalk.begin(), chalk.end(), 0LL);
        int N = chalk.size();
        k = k%tot;
        if (k == 0) return 0;

        for (int i=0; i<N; i++) {
            if ( k < chalk[i] ) return i;
            k -= chalk[i];
        }

        return 0;
    }
};