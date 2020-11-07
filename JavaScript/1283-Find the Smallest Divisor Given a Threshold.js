/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */
var smallestDivisor = function(nums, threshold) {
    let left = 1, right = Math.max(...nums);
    
    let getCount = (mid) =>{
        let count = 0;
        for (let num of nums){
            count += Math.ceil(num/mid);
        }
        return count;
    }
    
    while (left + 1 < right){
        let mid = left + Math.floor((right-left)/2)
        if (getCount(mid) > threshold){
            left = mid;
        } else{
            right = mid;
        }
    }
    if (getCount(left) <= threshold){
        return left;
    }else{
        return right;
    }
};