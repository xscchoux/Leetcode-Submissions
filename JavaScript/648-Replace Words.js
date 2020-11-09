/**
 * @param {string[]} dictionary
 * @param {string} sentence
 * @return {string}
 */
class TrieNode{
    constructor(){
        this.children = new Map();
        this.isWord = false;
    }
}

var replaceWords = function(dictionary, sentence) {
    const root = new TrieNode();
    for (let word of dictionary){
        let node = root;
        for (let char of word){
            if (!node.children.has(char)){
                node.children.set(char, new TrieNode())
            }
            node = node.children.get(char);
        }
        node.isWord = true;
    }
    
    let search = (word, node)=>{
        let tmp = "";
        for (const char of word){
            if (node.children.has(char) && node.children.get(char).isWord){
                tmp += char;
                return tmp;
            }
            else if (node.children.has(char)){
                tmp += char;
                node = node.children.get(char);
            }
            else{
                return null;
            }
        }
        return null;
    }
    
    
    
    let res = sentence.split(" ");
    for (let i=0; i<res.length; i++){
        let replace = search(res[i], root);
        if (replace){
            res[i] = replace;
        }
    }
    
    return res.join(" ");
};