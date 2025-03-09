using LL = long long;

LL p[18];
bool permCalculated = false;
void fillPerm() {
    p[0] = 1;
    for (int i=1; i<18; i++) {
        p[i] = p[i-1]*i;
    }
}


class Solution {
public:
    const LL limit = 10000000000000000LL;
    Solution() {
        if (!permCalculated) {
            fillPerm();
        }
    }
    bool willExceed(LL a, LL b) {
        return (b != 0 && a > limit/b);
    }

    LL permVal(int x) {   // 18! > 1e15
        if (x >= 18) return limit;
        return p[x];
    }

    vector<int> permute(int n, long long k) {
        int even = n/2, odd = (n+1)/2;

        // calculate all cases
        LL tot = 0LL;
        for (int num=1; num<=n; num++) {
            if ( (num&1) == 0 && n&1) continue;
            if (num&1) {
                if (willExceed(permVal(even), permVal(odd-1))) {
                    tot = limit+1;
                    break;
                }
                tot += p[even]*p[odd-1];
            } else {
                if (willExceed(permVal(even-1), permVal(odd))) {
                    tot = limit+1;
                    break;
                }
                tot += p[odd]*p[even-1];
            }
            if (tot > limit) break;
        }

        if (tot < k) return {};

        vector<int> candidates;
        for (int i=1; i<=n; i++) {
            candidates.push_back(i);
        }

        vector<int> res;
        for (int idx=0; idx<n; idx++) {
            for (int j=0; j<candidates.size(); j++) {
                int num = candidates[j];
                if (idx > 0 && res.back()%2 == num%2) continue;
                if ( (n-idx)&1 ) {
                    if (!(num&1) && odd > even) continue;  // the first number should always be odd if n is odd
                }
                
                LL cases = 0;
                if (num&1) {
                    cases += willExceed(permVal(odd-1), permVal(even))?limit:permVal(odd-1)*permVal(even);
                } else {
                    cases += willExceed(permVal(odd), permVal(even-1))?limit:permVal(odd)*permVal(even-1);
                }

                if (cases < k) {
                    k -= cases;
                } else {
                    res.push_back(num);
                    candidates.erase(find(begin(candidates), end(candidates), num));
                    if (num&1) {
                        odd--;
                    } else {
                        even--;
                    }
                    break;
                }
            }
        }

        return res;
    }
};