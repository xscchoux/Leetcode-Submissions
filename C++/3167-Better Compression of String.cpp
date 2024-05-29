class Solution {
public:
    string betterCompression(string compressed) {
        int i = 0;
        int c[26] = {};
        string res = "";

        for (int i=0, N = compressed.size(); i<N; i++) {
            if (isalpha(compressed[i])) {
                int j = i+1;
                int num = 0;
                while (j < N && !isalpha(compressed[j])) {
                    num = num*10;
                    num += (compressed[j] - '0');
                    j++;
                }
                c[compressed[i]-'a'] += num;
            }
        }
        for (int i=0; i<26; i++) {
            if (c[i] > 0) {
                res += static_cast<char>(i + 'a');
                res += to_string(c[i]);
            }
        }
        return res;
    }
};