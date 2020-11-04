/**
 * @param {number[]} nums
 * @param {number} m
 * @return {number}
 */
var splitArray = function(nums, m) {
    let max = 0, sum = 0;
    for (let i=0; i<nums.length; i++){
        max = Math.max(max, nums[i]);
        sum += nums[i];
    }
    
    let getCounts = (maxValue) =>{
        let count = 1;
        let summ = nums[0];
        for (let i=1; i<nums.length; i++){
            if (summ + nums[i] > maxValue){
                count++;
                summ = nums[i];
            }else{
                summ += nums[i];
            }
        }
        return count;
    }
    
    let left = max, right = sum;
    
    while (left + 1 < right){
        let mid = left + Math.floor((right-left)/2);
        if (getCounts(mid) > m){
            left = mid;
        } else{
            right = mid;
        }
    }
    if (getCounts(left) <= m){
        return left;
    }else{
        return right;
    }  
};