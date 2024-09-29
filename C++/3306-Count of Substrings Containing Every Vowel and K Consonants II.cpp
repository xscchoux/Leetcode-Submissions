class Solution {
public:
    bool isValid(unordered_map<char, int>& hmap, int consonant, int k) {
        return hmap['a'] > 0 && hmap['e'] > 0 && hmap['i'] > 0 && hmap['o'] > 0 && hmap['u'] > 0 && consonant == k;
    }
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    long long countOfSubstrings(string word, int k) {
        int N = word.size();
        int excess = 0, left = 0, consonant = 0;   // excessive vowels on the left side
        long long res = 0;
        unordered_map<char, int> hmap;

        for (int i=0; i<N; i++) {
            if (isVowel(word[i])) {
                hmap[word[i]]++;
            } else {
                consonant++;
            }
            if (consonant > k) {
                while (isVowel(word[left])) {
                    hmap[word[left]]--;
                    left++;
                } 
                consonant--;
                left++;
                excess = 0;
            }

            if (isValid(hmap, consonant, k)) {
                while (isVowel(word[left])) {
                    hmap[word[left]]--;
                    if (!isValid(hmap, consonant, k)) {
                        hmap[word[left]]++;
                        break;
                    } else {
                        left++;
                        excess++;
                    }
                }
                res += 1 + excess;
            }
        }
        return res;
    }
};