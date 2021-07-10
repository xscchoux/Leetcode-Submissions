/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    let one = 0, two = 0;
    for (let num of nums){
        two |= (one&num);
        one = one^num;
        let three = (one&two);
        two = two&(~three);
        one = one&(~three);
    }
    return one;
};