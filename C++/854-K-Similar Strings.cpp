// O(N^3)
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int N = s1.size();
        unordered_set<string> s;
        queue<string> q;
        q.push(s1);
        int res = 0;
        
        while (!q.empty()) {
            int length = q.size();
            while (length--) {
                string curr = q.front(); q.pop();
                if (curr == s2) return res;
                if (s.count(curr)) continue;
                s.insert(curr);
                int i=0;
                while (curr[i] == s2[i]) i++;
                for (int j=i; j<N; j++) {
                    if (curr[j] == s2[i] && curr[j] != s2[j]) {
                        swap(curr[j], curr[i]);
                        q.push(curr);
                        swap(curr[j], curr[i]);
                    }
                }
            }
            res++;
        }
        return N;
    }
};