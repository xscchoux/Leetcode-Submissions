var TrieNode = function(){
    this.children = new Map();
    this.prefix = 0;
    this.count = 0;
}


var Trie = function() {
    this.root = new TrieNode();
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    let curr = this.root;
    for (let w of word){
        if(!curr.children.has(w)){
            curr.children.set(w, new TrieNode())
        }
        curr = curr.children.get(w);
        curr.prefix+=1;
    }
    curr.count += 1;
};

/** 
 * @param {string} word
 * @return {number}
 */
Trie.prototype.countWordsEqualTo = function(word) {
    let curr = this.root;
    for (let w of word){
        if(!curr.children.has(w)){
            return 0
        }
        curr = curr.children.get(w);
    }
    return curr.count;
};

/** 
 * @param {string} prefix
 * @return {number}
 */
Trie.prototype.countWordsStartingWith = function(prefix) {
    let curr = this.root;
    for (let w of prefix){
        if(!curr.children.has(w)){
            return 0
        }
        curr = curr.children.get(w);
    }
    return curr.prefix;    
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.erase = function(word) {
    let curr = this.root;
    for (let w of word){
        if(!curr.children.has(w)){
            return
        }
        let nxt = curr.children.get(w)
        nxt.prefix -= 1
        if (nxt.prefix === 0){
            curr.children.delete(w);
            return
        }
        curr = nxt;
    }
    curr.count -= 1;
};

/** 
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.countWordsEqualTo(word)
 * var param_3 = obj.countWordsStartingWith(prefix)
 * obj.erase(word)
 */