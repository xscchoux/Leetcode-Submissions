struct TrieNode {
    TrieNode* children[26];
    bool isWord;
    explicit TrieNode():isWord(false){
        std::fill(children, children +26 , nullptr);
    }
    virtual ~TrieNode(){ // this makes code even faster
        for(TrieNode* e : children) delete e;
    }
};
class StreamChecker {
public:
    string curr = "";
    TrieNode* root = new TrieNode();
    StreamChecker(vector<string>& words) {
        for (string &w:words) {
            reverse(w.begin(), w.end());
            TrieNode* node = root;
            for (char c:w) {
                if (node->children[c-'a'] == nullptr) {
                    node->children[c-'a'] = new TrieNode();
                }
                node = node->children[c-'a'];
            }
            node->isWord = true;
        }
    }
    
    bool query(char letter) {
        curr += letter;
        TrieNode* node = root;
        for (int i=curr.size()-1; i>=0; i--) {
            if (node->children[curr[i]-'a'] == nullptr) return false;
            node = node->children[curr[i]-'a'];
            if (node->isWord) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */