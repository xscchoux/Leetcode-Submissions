class Solution {
public:
    string convertNumber(string s) {
        unordered_map<string, string> hmap = {{"one","1"}, {"two","2"}, {"three","3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}, {"zero", "0"}};

        string res = "";
        int idx = 0, N = s.size();
        
        while (idx < N) {
            if (N-idx >= 3 && hmap.contains(s.substr(idx, 3))) {
                res += hmap[s.substr(idx, 3)];
                idx += 3;
            } else if (N-idx >= 4 && hmap.contains(s.substr(idx, 4))) {
                res += hmap[s.substr(idx, 4)];
                idx += 4;
            } else if (N-idx >= 5 && hmap.contains(s.substr(idx, 5))) {
                res += hmap[s.substr(idx, 5)];
                idx += 5;
            } else {
                idx++;
            }
        }
        
        return res;
    }
};