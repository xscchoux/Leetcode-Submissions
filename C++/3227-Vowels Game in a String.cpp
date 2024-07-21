class Solution {
public:
    bool isVowel(char c) {
        return (c=='a'|| c=='e'||c=='i'||c=='o'||c=='u');
    }

    bool doesAliceWin(string s) {
        int N = s.size(), cnt = 0;
        for (int i=0; i<N; i++) {
            if (isVowel(s[i])) cnt++;
        }
        if (cnt > 0) return true;
        return false;
    }
};