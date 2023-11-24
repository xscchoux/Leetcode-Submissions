class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res = 0;
        int start = 0, N = piles.size();
        for (int i=N-2; i > start; i-=2){
            res += piles[i];
            start += 1;
        }
        return res;
    }
};