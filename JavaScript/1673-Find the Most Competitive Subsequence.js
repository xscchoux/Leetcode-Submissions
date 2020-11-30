/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var mostCompetitive = function(nums, k) {
    let stack = [];
    
    for (let i=0; i<nums.length; i++){
        let minStackLen = Math.max(0, k - nums.length + i );
        while (stack.length > minStackLen && stack[stack.length-1] > nums[i]){
            stack.pop();
        }
        stack.push(nums[i]);
    }
    return stack.slice(0,k);
};