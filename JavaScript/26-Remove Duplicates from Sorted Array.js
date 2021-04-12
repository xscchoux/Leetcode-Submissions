/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    if (!nums.length) return 0;
    
    let j = 0;
    
    for (let i=0; i<nums.length-1; i++){
        if (nums[i] < nums[i+1]){
            nums[j] = nums[i];
            j+=1;
        }
    }
    nums[j] = nums[nums.length-1];
    return j+1;
};