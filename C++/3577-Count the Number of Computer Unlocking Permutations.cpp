class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        // It's just (N-1)!
        int kMod = 1e9+7;
        
        long long res = 1;
        
        for (int i=1; i<complexity.size(); i++) {
            if (complexity[i] <= complexity[0]) return 0;
            res = (res*i)%kMod;
        }

        return res;
    }
};