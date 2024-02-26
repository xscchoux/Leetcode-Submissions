class Solution {
public:
    string lastNonEmptyString(string s) {
        int count[26];
        for (char c:s) count[c-'a']++;
        
        int maxVal = *max_element(count, count+26);
        
        int count2[26];
        string res = "";
        for (char c:s){
            count2[c-'a']++;
            if (count2[c-'a'] == maxVal) res += c;
        }
        
        return res;
    }
};