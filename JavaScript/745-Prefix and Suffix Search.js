/**
 * @param {string[]} words
 */
var WordFilter = function(words) {
    this.hmap = new Map();
    for (let [ind, word] of words.entries()){
        let length = word.length;
        for (let p=1; p<=length; p++){
            for (let s=0; s<length; s++){
                this.hmap.set(`${word.substring(0,p)} # ${word.substring(s)}`, ind);
            }
        }
    }
};

/** 
 * @param {string} prefix 
 * @param {string} suffix
 * @return {number}
 */
WordFilter.prototype.f = function(prefix, suffix) {
    let letter = `${prefix} # ${suffix}`;
    return this.hmap.has(letter)? this.hmap.get(letter):-1;
};

/** 
 * Your WordFilter object will be instantiated and called as such:
 * var obj = new WordFilter(words)
 * var param_1 = obj.f(prefix,suffix)
 */