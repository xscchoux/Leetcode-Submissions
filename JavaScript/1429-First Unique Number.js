/**
 * @param {number[]} nums
 */
var FirstUnique = function(nums) {
    this.hmap = new Map();
    this.queue = new Array();
    for (let num of nums){
        this.add(num);
    }
};

/**
 * @return {number}
 */
FirstUnique.prototype.showFirstUnique = function() {
    while (this.queue.length && this.hmap.get(this.queue[0]) === -1){
        this.queue.shift();
    }
    if (this.queue.length){
        return this.queue[0];
    }
    return -1;
};

/** 
 * @param {number} value
 * @return {void}
 */
FirstUnique.prototype.add = function(value) {
    if (this.hmap.has(value)){
        this.hmap.set(value, -1);
    }else{
        this.queue.push(value);
        this.hmap.set(value, 1);
    }
};

/** 
 * Your FirstUnique object will be instantiated and called as such:
 * var obj = new FirstUnique(nums)
 * var param_1 = obj.showFirstUnique()
 * obj.add(value)
 */