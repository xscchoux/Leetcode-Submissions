class Trie {
public:
    struct TrieNode {
        TrieNode* ch[26];
        int cnt;
        int isEnd;
        explicit TrieNode():cnt(0), isEnd(0){
            std::fill(ch, ch +26 , nullptr);
        }
        virtual ~TrieNode(){ // this makes code even faster
            for(TrieNode* e : ch) delete e;
        }
    };
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char w:word) {
            if (node->ch[w-'a'] == nullptr) {
                node->ch[w-'a'] = new TrieNode();
            }
            node = node->ch[w-'a'];
            node->cnt++;
        }
        node->isEnd++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char w:word) {
            if (node->ch[w-'a'] == nullptr) {
                node->ch[w-'a'] = new TrieNode();
            }
            node = node->ch[w-'a'];
        }
        return node->isEnd;       
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char w:prefix) {
            if (node->ch[w-'a'] == nullptr) {
                return 0;
            }
            node = node->ch[w-'a'];
        }
        return node->cnt;        
    }
    
    void erase(string word) {
        TrieNode* node = root;
        for (char w:word) {
            node = node->ch[w-'a'];
            --node->cnt; 
        }
        --node->isEnd;
    }
};
