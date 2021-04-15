/**
 * @param {number[]} nums
 * @return {number}
 */
var triangleNumber = function(nums) {
    nums.sort((a,b) => a-b);
    let n = nums.length;
    let res = 0;
    
    for (let k=n-1; k>=2; k--){
        let i=0, j=k-1;
        while (i<j){
            if (nums[i] + nums[j] > nums[k]){
                res += j-i;
                j--;
            }else{
                i++;
            }
        }
    }
    return res;
};