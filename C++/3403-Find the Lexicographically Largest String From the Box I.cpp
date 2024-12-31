class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word; // edge case, cannot split

        int N = word.size();
        string res = "";
        int length = N-numFriends+1;
        for (int i=0; i<N; i++) {
            if (N-i < length && i+1 < numFriends) break;  // not necessary
            string curr = word.substr(i, min(length, N-i));
            res = max(curr, res);
        }

        return res;
    }
};