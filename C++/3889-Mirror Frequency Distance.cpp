class Solution {
public:
    int mirrorFrequency(string s) {
        
        vector<int> charCnt(26, 0), numCnt(10, 0);

        for (char c:s) {
            if (isalpha(c)) {
                charCnt[c-'a']++;
            } else {
                numCnt[c-'0']++;
            }
        }

        int res = 0;
        for (int i=0; i<5; i++) {
            res += abs(numCnt[i] - numCnt[9-i]);
        }

        for (int i=0; i<13; i++) {
            res += abs(charCnt[i] - charCnt[25-i]);
        }        

        return res;
    }
};