class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<bool> fixed(n+m-1, false);
        string res = string(n+m-1, 'a');

        // T cases
        for (int i=0; i<n; i++) {
            if (str1[i] != 'T') continue;
            for (int j=0; j<m; j++) {
                if (fixed[i+j] && res[i+j] != str2[j]) {
                    return "";
                }
                fixed[i+j] = true;
                res[i+j] = str2[j];
            }
        }

        // F cases
        for (int i=0; i<n; i++) {
            if (str1[i] != 'F') continue;

            // check if substring is different from str2
            bool needChange = true;
            for (int j=m-1; j>=0; j--) {
                if (res[i+j] != str2[j]) {
                    needChange = false;
                    break;
                }
            }

            if (!needChange) continue;

            // make substring different from str2
            bool canChange = false;
            for (int j=m-1; j>=0; j--) {
                if (!fixed[i+j] && res[i+j] != 'z') {
                    res[i+j] = res[i+j]+1;
                    canChange = true;
                    break;
                }
            }

            if (!canChange) return "";
        }

        return res;
    }
};