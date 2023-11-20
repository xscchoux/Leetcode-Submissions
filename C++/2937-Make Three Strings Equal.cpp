class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int idx = 0;
        int minLen = min(s1.size(), min(s2.size(), s3.size()));
        int resLen = 0;
        
        for (int i = 0; i < minLen; i++){
            if (s1[i] == s2[i] && s2[i] == s3[i]) resLen++;
            else break;
        }

        if (resLen == 0) return -1;
        
        return s1.size() + s2.size() + s3.size() - 3*resLen;
    }
};