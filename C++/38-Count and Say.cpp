class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string curr = "1";

        while (--n > 0) {
            string tmp = "";
            for (int i=0, k=0 ; i<curr.size(); i=k) {
                char currChar = curr[i];
                while (k < curr.size() && curr[i] == curr[k]) {
                    k++;
                }
                tmp += to_string(k-i) + currChar;
            }
            curr = tmp;
        }

        return curr;
    }
};