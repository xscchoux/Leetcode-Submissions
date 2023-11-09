class Solution {
public:
    int countHomogenous(string s) {
        int kMod = 1e9+7;
        int res = 0;
        int count = 0;
        for (int i=0; i<s.size(); i++){
            if (i == 0 || s[i] != s[i-1]){
                count = 1;
            } else {
                count += 1;
            }
            res = (res + count)%kMod;
        }
        return res;
    }
};