/**
 * @param {number[]} nums
 * @return {boolean}
 */
var find132pattern = function(nums) {
    if (nums.length < 3) return false;
    
    let two = Number.NEGATIVE_INFINITY;
    let stack = [];
    
    for (let i=nums.length-1; i>=0; i--){
        if (nums[i] < two) return true;
        while (stack.length && nums[i] > stack[stack.length-1]){
            two = stack.pop();
        }
        stack.push(nums[i]);
    }
    
    return false;
};