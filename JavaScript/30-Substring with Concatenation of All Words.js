/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
    length = words[0].length;
    totlen = length*words.length;
    words.sort();
    res = [];
    
    for (let i=0; i<s.length-totlen+1; i++){
        let sub = [];
        for (let j=i; j<i+totlen; j+=length){
            sub.push(s.substr(j,length));
        }
        sub.sort();
        if (JSON.stringify(words) === JSON.stringify(sub)){
            res.push(i);
        }
    }
    return res;
    
};