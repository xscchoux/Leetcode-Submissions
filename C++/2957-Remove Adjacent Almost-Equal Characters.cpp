class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int res = 0;
        int count = 1;
        for (int i=1;i<word.size();i++){
            if (abs(word[i]-word[i-1]) <= 1){
                count++;
            } else {
                res += count/2;
                count = 1;
            }
        }
        
        res += count/2;
        
        return res;
    }
};