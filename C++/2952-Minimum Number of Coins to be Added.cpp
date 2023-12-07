class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int res = 0, reachable = 0;
        for (int coin:coins){
            while (reachable + 1 < coin && reachable < target){
                reachable += reachable+1;
                res++;
            }
            reachable += coin;
            if (reachable >= target) return res;
        }
        
        while (reachable < target){
            reachable += reachable + 1;
            res++;
        }
        return res;
    }
};