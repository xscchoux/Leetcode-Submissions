/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    nums.sort(function(a, b){
        a = a.toString();
        b = b.toString();
        if (a+b > b+a){
            return -1;
        }else{
            return 1;
        }
    })

    return nums[0] === 0 ? "0" : nums.join("");
    
};