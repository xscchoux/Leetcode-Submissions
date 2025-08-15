struct TrieNode {
    unordered_map<string, TrieNode*> children;
    int val = -1;
    virtual ~TrieNode() {
        for (auto& [key, child] : children) {
            delete child;
        }
    }
};

class FileSystem {
public:
    TrieNode* root;
    FileSystem() {
        root = new TrieNode();
        root->val = 0;
    }
    vector<string> split(const string& str, char delimiter) {
        vector<string> tokens;
        istringstream iss(str);
        string token;
        while (getline(iss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    bool createPath(string path, int value) {
        TrieNode* node = root;
        vector<string> p = split(path, '/');

        for (int i=1; i<p.size(); i++) {
            if (node->val == -1) return false;
            if (!node->children.contains(p[i])) {
                node->children[p[i]] = new TrieNode();
            }
            node = node->children[p[i]];
        }

        if (node->val != -1) return false;
        node->val = value;
        return true;
    }
    
    int get(string path) {
        TrieNode* node = root;
        vector<string> p = split(path, '/');

        for (int i=1; i<p.size(); i++) {
            if (!node->children.contains(p[i])) {
                return -1;
            }
            node = node->children[p[i]];
        }
        return node->val;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */