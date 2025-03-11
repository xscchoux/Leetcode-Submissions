class Solution {
public:
    bool fullySubstituted(string &text) {
        int N = text.size();
        for (int i=0; i<N-2; i++) {
            if (text[i] == '%' && text[i+1] >= 'A' && text[i+1] <= 'Z' && text[i+2] == '%') {
                return false;
            }
        }
        return true;
    }

    bool replaceAll(string& text, unordered_map<char, string>& hmap) {
        if (fullySubstituted(text)) {
            return true;
        }
        int idx = 0, N = text.size();
        string res;
        while (idx < N) {
            if (idx+2 < N && text[idx] == '%' && text[idx+1] >= 'A' && text[idx+1] <= 'Z' && text[idx+2] == '%' && hmap.contains(text[idx+1])) {
                res += hmap[text[idx+1]];
                idx += 3;
            } else {
                res.push_back(text[idx]);
                idx++;
            }
        }
        text = res;
        return false;
    }

    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        unordered_map<char, string> hmap;
        for (auto &r:replacements) {
            hmap[r[0][0]] = r[1];   // r[0][0] converts string r[0] to a char
        }

        while (!replaceAll(text, hmap)) {

        }
        return text;
    }
};