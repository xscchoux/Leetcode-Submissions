/**
 * @param {string} characters
 * @param {number} combinationLength
 */
var CombinationIterator = function(characters, combinationLength) {
    this.N = characters.length;
    this.bitmask = (1<<this.N)-1;
    this.k = combinationLength;
    this.characters = characters;
};

/**
 * @return {string}
 */
CombinationIterator.prototype.next = function() {
    this.hasNext();
    let res = new Array();
    for (let i=0; i<this.N; i++){
        if ( (this.bitmask >>(this.N-1-i)) & 1 ){
            res.push(this.characters[i]);
        }
    }
    this.bitmask--;
    return res.join("");
};

/**
 * @return {boolean}
 */
CombinationIterator.prototype.hasNext = function() {
    while (this.bitmask > 0 && this.bitmask.toString(2).split('1').length - 1 !== this.k){
        this.bitmask--;
    }
    return this.bitmask !== 0;
};

/** 
 * Your CombinationIterator object will be instantiated and called as such:
 * var obj = new CombinationIterator(characters, combinationLength)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */