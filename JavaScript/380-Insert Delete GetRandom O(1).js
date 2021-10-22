
var RandomizedSet = function() {
    this.hmap = new Map();
    this.arr = new Array();
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function(val) {
    if (!this.hmap.has(val)){
        let n = this.arr.length;
        this.arr.push(val);
        this.hmap.set(val, n);
        return true;
    }else{
        return false;
    }
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function(val) {
    if (this.hmap.has(val)){
        let n = this.arr.length, currIdx = this.hmap.get(val);
        this.arr[currIdx] = this.arr[n-1];
        this.arr.pop();
        this.hmap.delete(val);
        this.hmap.set(this.arr[currIdx], currIdx)
        return true;
    }else{
        return false;
    }
};

/**
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function() {
    return this.arr[Math.floor(Math.random()*this.arr.length)]
};