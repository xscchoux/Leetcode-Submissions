/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    let res = new Array();
    for (let num of nums){
        if (!res.length || num > res[res.length-1]){
            res.push(num);
        }else{
            let left = 0, right = res.length-1;
            while (left + 1 < right){
                let mid = left + Math.floor( (right - left)/2 );
                if (res[mid] < num ){
                    left = mid;
                }else{
                    right = mid;
                }
            }
            if (res[left] >= num){
                res[left] = num;
            }else{
                res[right] = num;
            }
        }
    }
    return res.length;
};