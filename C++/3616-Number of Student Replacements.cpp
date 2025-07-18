class Solution {
public:
    int totalReplacements(vector<int>& ranks) {
        int res = 0, minRank = ranks[0];

        for (int i=1; i<ranks.size(); i++) {
            if (ranks[i] < minRank) {
                minRank = ranks[i];
                res++;
            }
        }

        return res;
    }
};