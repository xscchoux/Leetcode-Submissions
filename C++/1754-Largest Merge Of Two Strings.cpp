class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res = "";
        int i1 = 0, i2 = 0;
        while (i1 < word1.size() && i2 < word2.size()){
            if (word1[i1] > word2[i2]){
                res += word1[i1++];
            } else if (word2[i2] > word1[i1]){
                res += word2[i2++];
            } else{
                if (word1.substr(i1) >= word2.substr(i2)){
                    res += word1[i1++];
                } else{
                    res += word2[i2++];
                }
            }
        }
        return res + word1.substr(i1) + word2.substr(i2);
    }
};