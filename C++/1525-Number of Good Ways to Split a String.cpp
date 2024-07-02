class Solution {
public:
    int numSplits(string s) {
        int N = s.size();
        vector<int> left(N), right(N);
        unordered_set<int> visited;

        for (int i=0; i<N; i++) {
            visited.insert(s[i]-'a');
            left[i] = visited.size();
        }

        visited.clear();
        int res = 0;
        for (int i=N-1; i>=1; i--) {
            visited.insert(s[i]-'a');
            right[i] = visited.size();
            if (right[i] == left[i-1]) res++;
        }

        return res;
    }
};