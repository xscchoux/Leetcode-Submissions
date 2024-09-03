using LL = long long;
class Solution {
public:
    int n, res = 0;
    vector<int> factorial = {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    LL fac(int n) {
        if (factorial[n] != -1) return factorial[n];
        else return factorial[n] = n*fac(n-1);
    }
    void count(string& s, int k, unordered_set<string>& used) {
        sort(s.begin(), s.end());
        if (used.find(s) != used.end()) return;
        used.insert(s);
        unordered_map<char, int> hmap;

        for (char c:s) hmap[c]++;
        LL deno = 1;
        for (auto &[k, v]:hmap) {
            deno *= fac(v);
        }
        LL tot = fac(n)/deno;
        if (hmap['0'] > 0) {
            hmap['0']--;
            LL deno0 = 1;
            for (auto &[k, v]:hmap) {
                deno0 *= fac(v);
            }
            LL tot0 = fac(n-1)/deno0;  // strings start with 0
            tot -= tot0;            
        }
        res += tot;
    }
    long long countGoodIntegers(int n, int k) {
        this->n = n;
        vector<string> put;
        unordered_set<string> used;
        put.push_back("");

        for (int i=0; i<(n+1)/2; i++) {
            vector<string> newPut;
            for (int num = (i==0?1:0); num<=9; num++) {
                for (auto s:put) {
                    newPut.push_back(s + to_string(num));
                }
            }
            put = newPut;
        }

        for (auto s:put) {
            string newS;
            if (n%2) {
                newS = s + string(s.rbegin()+1, s.rend());
                if (stoll(newS)%k == 0) count(newS, k, used);
            } else {
                newS = s + string(s.rbegin(), s.rend());
                if (stoll(newS)%k == 0) count(newS, k, used);
            }
        }

        return res;
    }
};