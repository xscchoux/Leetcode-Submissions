using LL = long long;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        LL res1 = (LL)cost1*need1 + (LL)cost2*need2;  
        int minNeed = min(need1, need2);
        int maxNeed = max(need1, need2);

        LL res2 = (LL)costBoth*minNeed + (LL)cost1*(need1-minNeed) + (LL)cost2*(need2-minNeed);
        LL res3 = (LL)costBoth*maxNeed;

        return min({res1, res2, res3});
    }
};