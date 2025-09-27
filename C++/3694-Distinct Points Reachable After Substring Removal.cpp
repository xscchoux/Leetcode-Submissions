class Solution {
public:
    int distinctPoints(string s, int k) {
        if (k == s.size()) return 1;
        unordered_set<long long> used;

        long long horizontal = 0, vertical = 0;
        for (int i=k; i<s.size(); i++) {
            if (s[i] == 'U') {
                vertical++;
            } else if (s[i] == 'D') {
                vertical--;
            } else if (s[i] == 'L') {
                horizontal--;
            } else {
                horizontal++;
            }
        }
        used.insert(horizontal*1e5 + vertical);

        for (int i = k; i<s.size(); i++) {
            if (s[i-k] == 'U') {
                vertical++;
            } else if (s[i-k] == 'D') {
                vertical--;
            } else if (s[i-k] == 'L') {
                horizontal--;
            } else {
                horizontal++;
            }

            if (s[i] == 'U') {
                vertical--;
            } else if (s[i] == 'D') {
                vertical++;
            } else if (s[i] == 'L') {
                horizontal++;
            } else {
                horizontal--;
            }            
            used.insert(horizontal*1e5 + vertical);
        }

        return used.size();
    }
};