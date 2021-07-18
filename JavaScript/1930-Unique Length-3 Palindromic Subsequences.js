/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequence = function(s) {
    let leftIndex = new Map(), rightIndex = new Map();
    
    for (let i=0; i<s.length; i++){
        if (!leftIndex.has(s[i])){
            leftIndex.set(s[i], i);
        }
        rightIndex.set(s[i], i);
    }
    
    let res = 0;
    let visited = new Set();
    for (let key of leftIndex.keys()){
        for (let i=leftIndex.get(key)+1; i<rightIndex.get(key); i++){
            if (!visited.has(`${key}-${s[i]}`)){
                visited.add(`${key}-${s[i]}`);
                res++;
            }
        }
    }
    return res;
};