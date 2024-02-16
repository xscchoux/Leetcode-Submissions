class TrieNode {
public:
    // member variables
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        isWord = false;
    }
    ~TrieNode(){}
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char w:word) {
            if (!node->children.count(w)) {
                node->children[w] = new TrieNode();
            }
            node = node->children[w];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char w:word) {
            if (!node->children.count(w)) {
                return false;
            }
            node = node->children[w];
        }
        return node->isWord;        
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char w:prefix) {
            if (!node->children.count(w)) {
                return false;
            }
            node = node->children[w];
        }
        return true;               
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */