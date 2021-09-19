/**
 * @param {string[]} nums
 * @return {string}
 */
var findDifferentBinaryString = function(nums) {
    const N = nums[0].length;
        
    for (let candidate=0; candidate < (1<<N); candidate++ ){
        let tmp = candidate.toString(2).padStart(N, '0');
        if (!nums.includes(tmp)) return tmp;
    }
};