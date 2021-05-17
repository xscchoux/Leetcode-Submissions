/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function(words) {
    
    words.sort(function(a, b){
        return a.length-b.length;
    })
    
    let dp = new Map();
    let res = 1;
    
    for (let word of words){
        dp.set(word, 1);
    }
    
    for (let word of words){
        for (let i=0; i<word.length; i++){
            let prev = word.substring(0,i) + word.substring(i+1);
            if (dp.has(prev)){
                dp.set(word, Math.max(dp.get(word), dp.get(prev)+1));
            }
        }
        res = Math.max(dp.get(word), res);
    }
    
    return res;
};