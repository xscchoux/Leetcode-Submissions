class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s) {
        int N = s.size();
        vector<char> arr;
        vector<int> cnt(26, 0), firstPos(26, N);
        for (int i=0; i<N; i++) {
            if (isVowel(s[i])) {
                int charNum = s[i] - 'a';
                arr.push_back(s[i]);
                cnt[charNum]++;
                if (firstPos[charNum] == N) {
                    firstPos[charNum] = i;
                }
            }
        }
        sort(begin(arr), end(arr), [&](char a, char b) {
            int charA = a-'a', charB = b-'a';
            return cnt[charA] > cnt[charB] || (cnt[charA] == cnt[charB] && firstPos[charA] < firstPos[charB]);
        });

        int idx = 0;
        for (int i=0; i<s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = arr[idx++];
            }
        }

        return s;
    }
};