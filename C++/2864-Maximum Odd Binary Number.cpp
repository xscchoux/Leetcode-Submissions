class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int N = s.size(), left = 0, right = N-1;
        string res = s;
        
        while (left <= right) {
            if (res[left] == '1') left++;
            if (res[right] == '0') right--;
            
            while (left<=right && res[left] == '0' && res[right] == '1') {
                res[left++] = '1';
                res[right--] = '0';
            }
        }
        
        res[left-1] = '0';
        res[N-1] = '1';
        
        return res;
    }
};