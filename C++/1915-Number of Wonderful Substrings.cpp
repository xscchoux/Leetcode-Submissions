class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> countState(2048, 0);
        countState[0] = 1;
        int kMod = 1e9+7;

        long long res = 0;
        int currState = 0;
        
        for (char w:word) {
            currState = currState^(1<<(w-'a'));
            res += countState[currState];
            for (int i=0; i<10; i++) {
                res += countState[currState^(1<<i)];
            }
            countState[currState]++;
        }

        return res;
    }
};