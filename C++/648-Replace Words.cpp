struct TrieNode {
    TrieNode* ch[26] = {};  // Initialize all pointers to nullptr
    bool isWord = false;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* t = new TrieNode();
        // build Trie
        for (string dict_word:dictionary) {
            TrieNode* node = t;
            for (char c:dict_word) {
                if (node->ch[c-'a'] == nullptr) {
                    node->ch[c-'a'] = new TrieNode();
                }
                node = node->ch[c-'a'];
            }
            node->isWord = true;
        }
        
        stringstream ss(sentence);
        string word;
        string res = "";
        while (ss >> word) {
            TrieNode* node = t;
            string curr = "";
            bool notFound = false;
            for (char w:word) {
                node = node->ch[w-'a'];
                if (node == nullptr) {
                    notFound = true;
                    break;
                }
                curr += w;
                if (node->isWord) break;
            }
            res += (notFound?word:curr) + " ";
        }
        res.pop_back();
        return res;
    }
};