/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function(s, t) {
    let res = 0;
    let toAdd = new Array(26).fill(0);
    const asciiA = 'a'.charCodeAt(0);
    
    for (let c of s){
        toAdd[c.charCodeAt(0)-asciiA] += 1;
    }
    
    for (let c of t){
        toAdd[c.charCodeAt(0)-asciiA] -= 1;
    }
    
    for (let val of toAdd){
        if (val > 0) res+=val;
    }
    
    return res;
};