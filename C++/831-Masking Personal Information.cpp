class Solution {
public:
    string maskPII(string s) {
        auto pos = s.find('@');
        string res;
        if (pos == string::npos) {
            for (int i=0; i<s.size(); i++) {
                if (isdigit(s[i])) res.push_back(s[i]);
            }
            int N = res.size();
            string pre = N==13?"+***-":N==12?"+**-":N==11?"+*-":"";
            return pre + "***-***-" + res.substr(N-4);
        } else {
            res = string(1, s[0]) + "*****" + s.substr(pos-1);
            transform(res.begin(), res.end(), res.begin(), ::tolower);
            return res;
        }
    }
};