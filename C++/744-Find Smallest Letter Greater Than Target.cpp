class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        bool found = false;
        for (int i=0; i<letters.size(); i++) {
            if (letters[i] > target) {
                if (!found) {
                    found = true;
                    res = letters[i];
                } else {
                    res = min(letters[i], res);
                }
            }
        }

        return found?res:letters[0];
    }
};