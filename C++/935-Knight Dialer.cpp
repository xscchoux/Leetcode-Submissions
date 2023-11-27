class Solution {
public:
    int kMod = 1e9+7;
    int memo[10][5001];
    unordered_map<int, vector<int>> hmap;
    // inside class, array, vector, or other container with multiple values are initialized in a function
    Solution (){
        hmap[0] = {4, 6};
        hmap[1] = {6, 8};
        hmap[2] = {7, 9};
        hmap[3] = {4, 8};
        hmap[4] = {0, 3, 9};
        hmap[5] = {};
        hmap[6] = {0, 1, 7};
        hmap[7] = {2, 6};
        hmap[8] = {1, 3};
        hmap[9] = {2, 4};
        memset(memo, -1, sizeof(memo));
    }
    
    int dp(int num, int remain){
        if (memo[num][remain] != -1) return memo[num][remain];
        if (remain == 1) return 1;
        long tot = 0;
        for (auto nxt:hmap[num]){
            tot = (tot + dp(nxt, remain-1))%kMod;
        }
        return memo[num][remain] = tot;
    }
    
    int knightDialer(int n) {
        long res = 0;
        for (int i=0; i<10; i++){
            res = (res + dp(i, n))%kMod;
        }
        return res;
    }
};