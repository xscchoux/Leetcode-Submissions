class Solution {
public:
    string lexSmallest(string s) {
        int N = s.size();
        string res = s;

        for (int end=1; end<N-1; end++) {
            string a = s;
            reverse(a.begin(), a.begin()+end+1);
            res = min(res, a);
            
            string b = s;
            reverse(b.begin()+end, b.end());
            res = min(res, b);
        }

        reverse(begin(s), end(s));

        return min(res, s);
    }
};