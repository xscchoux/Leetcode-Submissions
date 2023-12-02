class Solution {
public:
    int countDivisibleSubstrings(string word) {
        auto getIndex = [](char c){
            int index = (c-'a'+1)/3 + 1;
            return index;
        };
        
        int res = 0;
        
        for (int i=0; i<word.size(); i++){
            int tmp = 0;
            for (int j=i; j>=0; j--){
                tmp += getIndex(word[j]);
                res += (tmp%(i-j+1) == 0)?1:0;
            }
        }
        
        return res;
    }
};