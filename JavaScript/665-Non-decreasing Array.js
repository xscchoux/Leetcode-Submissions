/**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPossibility = function(nums) {
    if (nums.length === 1) return true;
    
    let count = 0;
    
    for (let i=1; i < nums.length; i++){
        if (nums[i] < nums[i-1]){
            if (count === 1){
                return false;
            }
            count += 1;
            if (i < 2 || nums[i] >= nums[i-2]){
                nums[i-1] = nums[i];
            }else{
                nums[i] = nums[i-1];
            }
        }
    }
    return true;
};