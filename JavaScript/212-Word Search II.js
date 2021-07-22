/**
 * @param {character[][]} board
 * @param {string[]} words
 * @return {string[]}
 */
var treeNode = function(){
    this.children = new Map();
    this.isWord = false;
}

var findWords = function(board, words) {
    let root = new treeNode();
    
    for (let word of words){
        let node = root;
        for (let char of word){
            if (!node.children.has(char)){
                node.children.set(char, new treeNode());
            }
            node = node.children.get(char);
        }
        node.isWord = word;
    }
    
    // let printTrie = (node) =>{
    //     if (node.isWord){
    //         console.log(node.isWord);
    //     }
    //     for (let nxt of node.children.keys()){
    //         printTrie(node.children.get(nxt));
    //     }
    // }
    // printTrie(root);
    
    let res = new Set();
    let row = board.length, col = board[0].length;
    let dfs = (r, c, node) =>{
        if (node.isWord){
            res.add(node.isWord);
        }
        
        for (let [dr, dc] of [[1,0], [0,1], [-1,0], [0,-1]]){
            let newR = r+dr, newC = c+dc;
            if (0<=newR && newR<row && 0<=newC && newC<col && node.children.has(board[newR][newC])){
                let tmp = board[newR][newC];
                board[newR][newC] = '#';
                dfs(newR, newC, node.children.get(tmp));
                board[newR][newC] = tmp;
            }
        }
    }
    
    for (let r=0; r<row; r++){
        let currNode = root;
        for (let c=0; c<col; c++){
            if (currNode.children.has(board[r][c])){
                let tmp = board[r][c];
                board[r][c] = '#';
                dfs(r, c, currNode.children.get(tmp));
                board[r][c] = tmp;
            }
        }
    }
    return [...res];
};