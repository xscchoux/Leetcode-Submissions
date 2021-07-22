// Fisher-Yates Algorithm

/**
 * @param {number[]} nums
 */
var Solution = function(nums) {
    this.nums = nums;
};

/**
 * Resets the array to its original configuration and return it.
 * @return {number[]}
 */
Solution.prototype.reset = function() {
    return this.nums;
};

/**
 * Returns a random shuffling of the array.
 * @return {number[]}
 */
Solution.prototype.shuffle = function() {
    const shuffled = this.nums.slice();
    for (let i=0; i<shuffled.length-1; i++){
        let index = i + Math.floor(Math.random()*(shuffled.length-i));
        [shuffled[index], shuffled[i]] = [shuffled[i], shuffled[index]];
    }
    return shuffled;
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(nums)
 * var param_1 = obj.reset()
 * var param_2 = obj.shuffle()
 */