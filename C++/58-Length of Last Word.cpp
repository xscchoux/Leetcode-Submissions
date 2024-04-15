class Solution {
public:
    int lengthOfLastWord(string s) {
        // use istringstream
        istringstream iss(s);
        string str;
        // Extract data from the stringstream
        while(iss) iss >> str;
        return str.size();
        
        // use isspace and isalpha
        int right = s.size()-1, cnt = 0;
        while (isspace(s[right])) {
            right--;
        }
        while (right >= 0 && isalpha(s[right])) {
            cnt++;
            right--;
        }
        return cnt;
    }
};