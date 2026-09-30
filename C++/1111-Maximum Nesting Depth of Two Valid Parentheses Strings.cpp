class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int N = seq.size();
        int d1 = 0, d2 = 0;
        vector<int> res;

        for (int i=0; i<N; i++) {
            if (seq[i] == '(') {
                if (d1 <= d2) {
                    res.push_back(0);
                    d1++;
                } else {
                    res.push_back(1);
                    d2++;
                }
            } else {
                if (d1 >= d2) {
                    res.push_back(0);
                    d1--;
                } else {
                    res.push_back(1);
                    d2--;
                }
            }
        }        

        return res;
    }
};