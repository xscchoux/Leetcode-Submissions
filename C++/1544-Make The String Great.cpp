class Solution {
public:
    string makeGood(string s) {
        vector<char> arr;
        for (char c:s) {
            if (!arr.empty() && ((isupper(c) && arr.back() == tolower(c)) || (islower(c) && arr.back() == toupper(c))) ) {
                arr.pop_back();
            } else {
                arr.push_back(c);
            }
        }
        
        return accumulate(arr.begin(), arr.end(), string());
    }
};