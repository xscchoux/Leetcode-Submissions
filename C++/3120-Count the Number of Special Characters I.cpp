class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> special(26*2, false); 
        int cnt = 0;
        for (char c:word) {
            if (isupper(c)) {
                int num = c-'A';
                special[26+num] = true;
            } else {
                int num = c-'a';
                special[num] = true;                
            }
        }

        for (int i=0; i<26; i++) {
            if (special[i] && special[26+i]) cnt++;
        }

        return cnt;
    }
};