class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        int N = s.size();

        for (int i=0; i<N; i++) {
            last[s[i]-'a'] = i;
        }

        vector<int> res;
        int left = 0, maxEnd = 0;
        for (int i=0; i<N; i++) {
            maxEnd = max(maxEnd, last[s[i]-'a']);
            if (i == maxEnd) {
                res.push_back(i-left+1);
                left = i+1;
            }
        }

        return res;
    }
};