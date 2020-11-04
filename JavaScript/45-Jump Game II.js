/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    let lastFarthest = 0
    let step = 0
    let currFarthest = 0
    
    for (let i=0; i<nums.length; i++){
        if (i > lastFarthest){
            step += 1;
            lastFarthest = currFarthest;
            if (currFarthest >= nums.length-1){
                break;
            }
        }
        if (i + nums[i] > currFarthest){
            currFarthest = i + nums[i];
        }
    }
    return step;
};