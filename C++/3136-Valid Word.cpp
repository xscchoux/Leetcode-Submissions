class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool vowel = false, consonant = false;

        for (char c:word) {
            if (!isalnum(c)) {
                return false;
            }
            if (isalpha(c)) {
                char curr = tolower(c);
                if (curr == 'a'||curr == 'e'||curr =='i'||curr == 'o'||curr == 'u') {
                    vowel = true;
                } else {
                    consonant = true;
                }
            }
        }

        return vowel && consonant;
    }
};