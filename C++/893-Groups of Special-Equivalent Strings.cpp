class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> visited;
        for (string word:words) {
            string odd, even;
            for (int i=0; i<word.size(); i++) {
                if (i%2) even += word[i];
                else odd += word[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            visited.insert(even+odd);
        }
        
        return visited.size();
    }
};