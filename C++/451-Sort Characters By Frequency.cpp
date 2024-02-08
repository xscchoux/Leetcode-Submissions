class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char c:s) {
            count[c]++;
        }
        sort(s.begin(), s.end(), [&](const char a, const char b){
            return count[a] > count[b] || (count[a] == count[b] && a < b);
        });
        return s;
    }
};