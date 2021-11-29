/**
 * @param {string[]} words
 * @return {string[][]}
 */
var wordSquares = function(words) {
    const N = words[0].length;
    let prefixMap = new Map();
    for (let word of words){
        for (let i=1; i<N; i++){
            const w = word.substring(0, i);
            if (prefixMap.has(w)){
                prefixMap.get(w).push(word);
            }else{
                prefixMap.set(w, new Array(1).fill(word));
            }
        }
    }
    
    let res = new Array();
    
    let backtrack = (idx, curr) =>{
        if (curr.length == words[0].length){
            res.push(curr);
            return;
        }
        let prefix = "";
        for (let prev of curr){
            prefix += prev[idx];
        }
        if (prefixMap.has(prefix)){
            for (let nxt of prefixMap.get(prefix)){
                backtrack(idx+1, curr.concat([nxt]));
            }
        }
    }
    
    for (let word of words){
        backtrack(1, new Array(1).fill(word));
    }
    return res;
};