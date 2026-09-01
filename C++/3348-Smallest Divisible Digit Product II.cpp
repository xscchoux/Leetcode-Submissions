class Solution {
public:
    string smallestNumber(string num, long long t) {
        int N = num.size();
        long long tmp = t;
        for (int i=2; i<=9; i++) {
            while (tmp%i == 0) {
                tmp = tmp/i;
            }
        }

        if (tmp > 1) return "-1";

        // rem[i] represents the product of the digits i~n−1 must still contribute to make num divisible by t
        vector<long long> rem(N+1, 0);
        rem[0] = t;
        int pos = N-1;

        
        // fill rem, and check if num is divisible by t
        for (int i=0; i<N; i++) {
            if (num[i] == '0') {
                pos = i;
                break;
            }
            rem[i+1] = rem[i]/gcd(num[i]-'0', rem[i]);
        }

        // Don't put this inside the for loop above. Note this case: num = 129709, t = 18
        if (rem[N] == 1) {
            return num; 
        }

        // try to get the anwer that has the same length as num
        for (int i=pos; i>=0; i--) {
            while (++num[i] <= '9') {
                long long tNos = rem[i]/gcd(num[i]-'0', rem[i]);
                int k = 9;
                for (int j=N-1; j>i; j--) {
                    while (tNos%k) {
                        k--;
                    }
                    num[j] = '0' + k;
                    tNos /= k;
                }
                if (tNos == 1) {
                    return num;
                }
            }
        }

        // when the length of the answer is greater than N
        string res = "";
        for (int i=9; i>=2; i--) {
            while (t%i == 0) {
                res += '0' + i;
                t /= i;
            }
        }
        
        // Note that sometimes res is smaller than num, Ex: num = "78", t = 42  => res = "67"
        // In this case, we need to prepend enough '1'
        res += string(max(N+1-(int)res.size(), 0), '1');
        reverse(begin(res), end(res));

        return res;
    }
};