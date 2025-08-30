class Solution {
public:
    int score(vector<string>& cards, char x) {
        vector<int> bucket0(26, 0), bucket1(26, 0);
        int same = 0;

        // bucket0:_x, bucket1:x_
        for (auto &c:cards) {
            if (c[0] == c[1] && c[0] == x) {
                same++;   // cards with letter xx
                continue;
            }
            if (c[1] == x) {
                bucket0[c[0]-'a']++;
            } else if (c[0] == x) {
                bucket1[c[1]-'a']++;
            }
        }

        int N0 = 0, M0 = 0;
        for (int num:bucket0) {
            N0 += num;
            M0 = max(M0, num);
        }

        int res0 = min(N0/2, N0-M0);  // maximum number of pairs using bucket0
        int remain0 = N0 - res0*2;    // not paired cards in bucket0

        int N1 = 0, M1 = 0;
        for (int num:bucket1) {
            N1 += num;
            M1 = max(M1, num);
        }

        int res1 = min(N1/2, N1-M1);  // maximum number of pairs using bucket1
        int remain1 = N1 - res1*2;    // not paired cards in bucket1

        if (remain0 + remain1 >= same) {
            return res0 + res1 + same;   // pair xx with not paired cards in bucket0 and bucket1
        } else {  // remain0 + remain1 < same
            int excess = same - remain0 - remain1;  // pair xx with not paired cards, and still have remaining xx cards
            if (excess >= res0*2 + res1*2) {
                return remain0 + remain1 + res0*2 + res1*2;
            } else {
                return remain0 + remain1 + excess + (res0*2 + res1*2 - excess)/2;
            }
        }
    }
};