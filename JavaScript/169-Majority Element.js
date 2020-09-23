/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let curr = nums[0]
    let count = 0;
    for (let num of nums){
        if (num === curr) count++;
        else {
            count--;
            if (count < 0){
                curr = num;
                count = 1;
            }
        }
    }
    return curr;
};