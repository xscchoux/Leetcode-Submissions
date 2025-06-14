#include <iostream>
using namespace std;
class Solution {
public:
    int N;
    long long res = 0;
    void helper(int idx, string& s, vector<vector<vector<int>>>& cnt) {
        if (idx == N) return;
        
        int curr = s[idx] - '0';
        // cout << " curr = " << curr << endl;
        if (idx == 0) {
            for (int num=1; num<=9; num++) {
                cnt[idx][num][curr%num]++;
            }
            if (curr != 0) res++;
        } else {
            for (int num=1; num<=9; num++) {
                for (int rem=0; rem<num; rem++) {
                    cnt[idx][num][(10*rem+curr)%num] += cnt[idx-1][num][rem];
                    // cout << " idx = " << idx << " num = " << num  << " rem = " << rem << " (10*rem+curr) mod num  = " << (10*rem+curr)%num << " cnt[idx-1][num][rem] = " << cnt[idx-1][num][rem] << endl;
                }
                cnt[idx][num][curr%num]++;
            }

            if (curr != 0) {
                // for (int rem=0; rem<=9; rem++) {
                //     if ((10*rem+curr)%curr == 0) {
                //         res += cnt[idx][curr][rem];
                //     }
                // }
                res += cnt[idx][curr][0];
            }
        }
        // cout << " idx = " << idx << " res = " << res << endl;
        helper(idx+1, s, cnt);
        
    }
    long long countSubstrings(string s) {
        N = s.size();
        vector<vector<vector<int>>> cnt(N, vector<vector<int>>(10, vector<int>(10, 0)));

        helper(0, s, cnt);

        return res;
    }
};


int main() {
    Solution sol;
    string s1 = "12936";
    cout << sol.countSubstrings(s1) << endl;
    Solution sol2;
    string s2 = "5701283";
    cout << sol2.countSubstrings(s2) << endl;
    Solution sol3;
    string s3 = "1010101010";
    cout << sol3.countSubstrings(s3) << endl;
}