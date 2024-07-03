class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string data;
        int res = 0;
        char delimiter = '\n';
        unordered_map<int, int> length;  // number of tab : max length
        
        while (getline(ss, data, delimiter)) {
            int numTab = 0, idx = 0;
            while (data[idx] == '\t') {
                numTab++;
                idx++;
            }
            if (numTab == 0) {
                length[numTab] = data.size();
            } else {
                length[numTab] = length[numTab-1] + 1 + data.substr(idx).size();
            }
            if (data.find('.') != string::npos) {
                res = max(res, length[numTab]);
            }
        }

        return res;
    }
};