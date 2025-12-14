class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseWords(string s) {
        vector<string> arr;
        stringstream ss(s);
        string word;
        while (ss >> word) arr.push_back(word);

        int vowelInFirst = -1;

        string res = "";
        for (int i=0; i<arr.size(); i++) {
            int vowelCnt = 0;
            for (char c:arr[i]) {
                if (isVowel(c)) {
                    vowelCnt++;
                }
            }
            if (vowelCnt == vowelInFirst) {
                reverse(begin(arr[i]), end(arr[i]));
            }
            if (vowelInFirst == -1) {
                vowelInFirst = vowelCnt;
            }
            if (i > 0) res += " ";
            res += arr[i];
        }

        return res;
    }
};