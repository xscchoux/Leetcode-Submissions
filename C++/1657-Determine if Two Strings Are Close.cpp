class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int wordBit1 = 0, wordBit2 = 0;
        vector<int> arr1(26, 0), arr2(26, 0);
        for (int c:word1) {
            wordBit1 |= 1 << (c-'a');
            arr1[c-'a']++;
        }
        
        for (int c:word2) {
            wordBit2 |= 1 << (c-'a');
            arr2[c-'a']++;
        }
        
        if (wordBit1 != wordBit2) return false;
        
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        return arr1 == arr2;
    }
};