class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        int res = 0;

        for (int num:answers) {
            cnt[num]++;
        }

        for (auto &[k, v]:cnt) {
            res += (v+k)/(k+1)*(k+1);
        }

        return res;
    }
};