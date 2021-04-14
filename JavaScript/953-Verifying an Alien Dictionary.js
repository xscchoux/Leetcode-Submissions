/**
 * @param {string[]} words
 * @param {string} order
 * @return {boolean}
 */
var isAlienSorted = function(words, order) {
    
    let hmap = new Map();
    
    for (let j=0; j<order.length; j++){
        hmap.set(order[j], j);
    }
    
    for (let i=1; i < words.length; i++){
        let word1 = words[i-1];
        let word2 = words[i];
        let ind = 0;
        while (ind < word1.length && ind < word2.length){
            if (hmap.get(word1[ind]) < hmap.get(word2[ind])) break;
            else if (hmap.get(word1[ind]) > hmap.get(word2[ind])) return false;
            else ind++;
        }
        if (ind === word2.length && word1.substr(ind).length > 0) return false;
    }
    return true;
};