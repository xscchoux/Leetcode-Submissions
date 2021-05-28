/**
 * @param {string[]} words
 * @return {number}
 */
var maxProduct = function(words) {
    let masks = new Array();
    const baseCode = ('a').charCodeAt(0);

    for (let word of words){
        let mask = 0;
        for (let i=0; i<word.length; i++){
            mask |= 1<<(word.charCodeAt(i) - baseCode);
        }
        masks.push(mask);
    }
    
    let res = 0;
    
    for (let i=0; i<words.length-1; i++){
        for (let j=i+1; j<words.length; j++){
            if ( (masks[i] & masks[j]) === 0){
                res = Math.max(res, words[i].length * words[j].length);
            }
        }
    }
    return res;
};