/**
 * @param {string[]} words
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var shortestDistance = function(words, word1, word2) {
    let i1 = -1, i2 = -1;
    let res = words.length;
    for (let i=0; i<words.length; i++){
        if (words[i] === word1){
            i1 = i;
        } else if (words[i] === word2){
            i2 = i;
        }
        
        if (i1 !== -1 && i2 !== -1){
            res = Math.min(res, Math.abs(i1-i2));
        }
    }
    return res;
};