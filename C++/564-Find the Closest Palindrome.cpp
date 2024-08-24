// My brute-force solution
using LL = long long;
class Solution {
public:
    int N;
    LL res = LLONG_MAX;
    string resS;
    void dfs(int ind, string& n, string prev, LL number_n) {
        if (ind == (N+1)/2) {
            string reversed_prev = prev, newS;
            reverse(reversed_prev.begin(), reversed_prev.end());
            if (N%2) {
                newS = prev + reversed_prev.substr(1);
            } else {
                newS = prev + reversed_prev;                
            }
            LL diff = abs(stol(newS)-number_n);            
            if (diff <= res && diff != 0) {
                if (diff < res) {
                    res = diff;
                    resS = newS;
                } else {
                    if (newS < resS) resS = newS;
                }
            }
            return;
        }
        int curr = n[ind]-'0';
        for (int i=-1; i<=1; i++) {
            int num = (curr + i + 10)%10;
            dfs(ind+1, n, prev + to_string(num), number_n);
        }


    }
    string nearestPalindromic(string n) {
        this->N = n.size();
        LL number_n = stol(n);
        dfs(0, n, "", number_n);

        // check 1001 when n is 999
        LL greater = pow(10, N) + 1;
        if (greater - number_n < res) {
            return to_string(greater);
        }

        // check 999 when n is 1000
        LL allNine = pow(10, N-1)-1;
        LL diff = number_n - allNine;

        if (diff <= res) {
            resS = to_string(allNine);
        }

        return resS;
    }
};




// very clever and efficient one
using LL = long long;
class Solution {
public:
    string nearestPalindromic(string n) {
        int N = n.size();
        unordered_set<LL> s;
        s.insert(pow(10, N)+1);
        s.insert(pow(10, N-1)-1);

        LL leftHalf = stol(n.substr(0, (N+1)/2));
        for (int i=-1; i<=1; i++) {
            string leftStr = to_string(leftHalf + i);
            string palindrome = leftStr + string(leftStr.rbegin() + (N&1), leftStr.rend());
            s.insert(stol(palindrome));
        }

        
        LL res = INT_MAX, diff = INT_MAX;
        LL num = stol(n);
        s.erase(num); // in case num is alreay a palindrome

        for (LL p:s) {
            if (abs(p-num) < diff) {
                diff = abs(p-num);
                res = p;
            } else if (abs(p-num) == diff && p < res) {
                res = p;
            }
        }

        return to_string(res);
    }
};