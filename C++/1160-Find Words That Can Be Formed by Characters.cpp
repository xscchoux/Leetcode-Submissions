class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> char_arr(26, 0);
        for (char c:chars) char_arr[c-'a']++;
        
        int res = 0;
        for (string word:words){
            vector<int> tmp(26, 0);
            for (char c:word){
                tmp[c-'a']++;
            }
            bool pass = true;
            for (int i=0; i<26; i++){
                if (tmp[i] > char_arr[i]){
                    pass = false;
                    break;
                }
            }
            if (pass) res += word.size();
        }
        return res;
    }
};