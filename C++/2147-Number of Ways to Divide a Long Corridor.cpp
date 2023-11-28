class Solution {
public:
    int numberOfWays(string corridor) {
        int tot = 0;
        for (char c:corridor){
            if (c == 'S') tot++;
        }
        
        if (tot == 0 || tot%2 != 0) return 0;
        
        int seats = 0, count = 0, kMod = 1e9+7;
        long res = 1;
        
        for (char c:corridor){
            if (c == 'S') seats++;
            if (seats%2 == 0 && seats != 0){
                count++;
            } else if (count > 0){
                res = (res*count)%kMod;
                count = 0;
            }
        }
        return (int) res;
    }
};