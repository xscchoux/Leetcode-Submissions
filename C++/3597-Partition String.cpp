class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> visited;

        string curr = "";
        vector<string> res;

        for (int i=0; i<s.size(); i++) {
            curr += s[i];
            if (!visited.contains(curr)) { // O(1) in average
                visited.insert(curr);
                res.push_back(curr);
                curr = "";        
            }
        }

        return res;
    }
};