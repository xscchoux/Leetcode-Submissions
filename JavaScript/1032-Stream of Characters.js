var TrieNode = function(){
    this.children = new Map();
    this.isWord = false;
};
/**
 * @param {string[]} words
 */
var StreamChecker = function(words) {
    this.root = new TrieNode();
    this.queue = new Array();
    for (let word of words){
        let node = this.root;
        for (let i=word.length-1; i>=0; i--){
            if (!node.children.has(word[i])){
                node.children.set(word[i], new TrieNode());
            }
            node = node.children.get(word[i]);
        }
        node.isWord = true;
    }
};

/** 
 * @param {character} letter
 * @return {boolean}
 */
StreamChecker.prototype.query = function(letter) {
    this.queue.unshift(letter);
    
    let node = this.root;
    
    for (let i=0; i < this.queue.length; i++){
        if (node.children.has(this.queue[i])){
            node = node.children.get(this.queue[i]);
        }else{
            return false;
        }
        if (node.isWord) return true;
    }
    return node.isWord === true;
};

/** 
 * Your StreamChecker object will be instantiated and called as such:
 * var obj = new StreamChecker(words)
 * var param_1 = obj.query(letter)
 */