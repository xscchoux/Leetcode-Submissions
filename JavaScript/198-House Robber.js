/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (nums.length === 0) return 0;
    
    let prev = 0, curr = nums[0]
    
    for (let i=1; i<nums.length; i++){
        [prev, curr] = [curr, Math.max(curr, nums[i]+prev)];
    }
    
    return curr;
    
};