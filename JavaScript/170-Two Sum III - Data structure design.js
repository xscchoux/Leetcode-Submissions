/**
 * Initialize your data structure here.
 */
var TwoSum = function() {
    this.count = new Map();
};

/**
 * Add the number to an internal data structure.. 
 * @param {number} number
 * @return {void}
 */
TwoSum.prototype.add = function(number) {
    this.count.set(number, ( this.count.get(number)||0 ) + 1)
};

/**
 * Find if there exists any pair of numbers which sum is equal to the value. 
 * @param {number} value
 * @return {boolean}
 */
TwoSum.prototype.find = function(value) {
    for (let key of this.count.keys()){
        let complement = value - key;
        if (complement !== key && this.count.has(complement)) return true;
        else if (complement === key && this.count.get(complement) > 1) return true;
    }
    return false;
};

/** 
 * Your TwoSum object will be instantiated and called as such:
 * var obj = new TwoSum()
 * obj.add(number)
 * var param_2 = obj.find(value)
 */