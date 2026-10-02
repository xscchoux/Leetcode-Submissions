class Solution {
public:
    vector<string> res;
    void create(int bra, int ket, string& s) {
        if (bra == 0 && ket == 0) {
            res.push_back(s);
            return;
        }

        if (bra < ket) {
            s.push_back(')');
            create(bra, ket-1, s);
            s.pop_back();
        }

        if (bra > 0) {
            s.push_back('(');
            create(bra-1, ket, s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        create(n, n, s);

        return res;
    }
};