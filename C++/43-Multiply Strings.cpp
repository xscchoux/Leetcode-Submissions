class Solution {
public:
    string multiply(string num1, string num2) {
        int N1 = num1.size(), N2 = num2.size();
        vector<int> res(N1+N2, 0);

        for (int i=0; i<N1; i++) {
            int int1 = num1[N1-i-1] - '0';
            for (int j=0; j<N2; j++) {
                int int2 = num2[N2-j-1] - '0';
                int val = int1*int2 + res[i+j];
                int q = val/10, r = val%10;
                res[i+j] = r;
                res[i+j+1] += q;
            }
        }

        while (!res.empty() && res.back() == 0) {
            res.pop_back();
        }
        string ans;
        for (int i=res.size()-1; i>=0; i--) {
            ans += (res[i]+'0');
        }

        return ans.empty()?"0":ans;
    }
};