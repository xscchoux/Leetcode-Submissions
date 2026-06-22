class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> cnt;

        for (char c:text) {
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') {
                cnt[c]++;
            } 
        }

        int res = INT_MAX;
        res = min(res, cnt['b']);
        res = min(res, cnt['a']);
        res = min(res, cnt['l']/2);
        res = min(res, cnt['o']/2);
        res = min(res, cnt['n']);
        
        return res;
    }
};