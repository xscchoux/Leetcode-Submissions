class Solution {
public:
    string longestPalindrome(string s) {
        // expand from centers
        int res = 1;
        int start = 0, end = 0;
        for (int i=0; i<s.size(); i++){
            int left = i, right = i;
            while (left >= 0 and right < s.size()){
                if (s[left] == s[right]){
                    if (right-left+1 > res){
                        res = right-left+1;
                        start = left;
                        end = right;
                    }
                    left--;
                    right++;
                }else {
                    break;
                }
            }
        }
        
        for (int i=0; i+1 <s.size(); i++){
            if (s[i] != s[i+1]) continue;
            int left = i, right = i+1;
            while (left >= 0 and right < s.size()){
                if (s[left] == s[right]){
                    if (right-left+1 > res){
                        res = right-left+1;
                        start = left;
                        end = right;
                    }
                    left--;
                    right++;
                }else {
                    break;
                }
            }
        }
        
        return s.substr(start, end-start+1);
    }
};