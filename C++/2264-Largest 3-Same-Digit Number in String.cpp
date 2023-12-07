class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        for (char c:"0123456789"){
            for (int i=1; i<num.size()-1; i++){
                if (num[i] == c && num[i-1] == num[i] && num[i] == num[i+1]){
                    res = string(3, c);
                    break;
                }
            }
        }
        return res;
    }
};