class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int count[26];
        fill(count, count+26, 0);
        vector<int> length;
        int evenPairs = 0;
        int res = 0;
        
        for (string word:words) {
            for (char c:word) {
                count[c-'a']++;
            }
            length.push_back(word.size());
        }
        
        for (int num:count) evenPairs += num/2;
        
        sort(length.begin(), length.end());
        
        for (int len:length) {
            if (len/2 <= evenPairs) {
                evenPairs -= len/2;
                res++;
            }
        }
        
        return res;
    }
};