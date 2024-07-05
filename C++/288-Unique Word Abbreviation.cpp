class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> abbrToWord;
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto &d:dictionary) {
            string abbrString = d[0] + to_string(d.size() - 2) +d[d.size()-1];
            abbrToWord[abbrString].insert(d);
        }
    }
    
    bool isUnique(string word) {
        string wordAbbr = word[0] + to_string(word.size() - 2) + word[word.size()-1];
        if (abbrToWord.find(wordAbbr) == abbrToWord.end()) {
            return true;
        } else {
            if (abbrToWord[wordAbbr].size() == 1 && *(abbrToWord[wordAbbr].begin()) == word ) {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */