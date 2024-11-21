class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fWords;
        int N = words.size();
        for (string &word:words) {
            int num = 26, cnt = 0;
            for (char c:word) {
                int charNum = c-'a';
                if (charNum < num) {
                    num = charNum;
                    cnt = 1;
                } else if (charNum == num) {
                    cnt++;
                }
            }
            fWords.push_back(cnt);
        }
        sort(begin(fWords), end(fWords));
        

        vector<int> res;
        for (string &query:queries) {
            int num = 26, cnt = 0;
            for (char c:query) {
                int charNum = c-'a';
                if (charNum < num) {
                    num = charNum;
                    cnt = 1;
                } else if (charNum == num) {
                    cnt++;
                }
            }
            int idx = upper_bound(begin(fWords), end(fWords), cnt) - begin(fWords);
            res.push_back(N-idx);
        }

        return res;
    }
};