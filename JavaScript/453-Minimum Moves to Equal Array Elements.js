/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
    return nums.reduce((x, acc) => x + acc) - Math.min(...nums)*nums.length;
};