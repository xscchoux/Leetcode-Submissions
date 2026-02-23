class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int N = s.size();
        unordered_set<string> subSet;

        string curr = "";
        for (int i=0; i<s.size(); i++) {
            curr += s[i];
            if (curr.size() > k) {
                curr.erase(0, 1);
            }
            if (curr.size() == k) {
                subSet.insert(curr);
            }
        }

        return subSet.size() == pow(2, k);
    }
};



// Use bitset, much faster
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return 0;

        bitset<1<<20> seen;
        unsigned int mask = 0, M = (1<<k)-1;
        for (int i=0; i<k; i++) {
            mask = (mask<<1) + (s[i]-'0');
        }
        seen[mask] = 1;

        for (int i=k; i<s.size(); i++) {
            mask = (mask << 1);
            mask &= M;
            mask |= (s[i]-'0');
            seen[mask] = 1;
        }
           

        return seen.count() == (1<<k);
    }
};