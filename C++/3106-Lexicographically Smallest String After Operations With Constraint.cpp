class Solution {
public:
    string getSmallestString(string s, int k) {
        
        for (int i=0; i<s.size(); i++) {
            int diff = min(s[i]-'a', 'a'-s[i]+26);
            if (diff <= k) {
                s[i] = 'a';
                k -= diff;
                if (k == 0) break;
            } else {
                s[i] = char(s[i]-k);
                break;
            }
        }
        return s;
    }
};