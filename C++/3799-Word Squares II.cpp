class Solution {
public:
    vector<vector<string>> res;
    void construct(vector<string>& words, int i, int j, int k, int l) {
        vector<int> idx = {i, j, k, l};

        do {
            string a = words[idx[0]];  // top
            string b = words[idx[1]];  // left
            string c = words[idx[2]];  // right
            string d = words[idx[3]];  // bottom
            if (a[0] == b[0] && a[3] == c[0] && d[0] == b[3] && d[3] == c[3]) {
                res.push_back({a, b, c, d});
            }

        } while (next_permutation(idx.begin(), idx.end()));

    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        int N = words.size();
        sort(begin(words), end(words));
        for (int i=0; i<=N-4; i++) {
            for (int j=i+1; j<=N-3; j++) {
                for (int k=j+1; k<=N-2; k++) {
                    for (int l=k+1; l<=N-1; l++) {
                        construct(words, i, j, k, l);
                    }
                }
            }
        }
        sort(begin(res), end(res));
        return res;
    }
};