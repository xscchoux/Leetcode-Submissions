/**
 * @param {number[]} arr
 * @param {number} target
 * @return {number}
 */
var findBestValue = function(arr, target) {
    let calSum = (mid) =>{
        let res = 0;
        for (let num of arr){
            if (num > mid) res += mid;
            else res += num;
        }
        return res;
    }
    
    let left = 0, right = Math.max(...arr);
    
    while (left+1<right){
        let mid = left + ((right-left)>>1)
        if (calSum(mid) == target){
            return mid;
        }else if (calSum(mid) > target){
            right = mid;
        }else{
            left = mid
        }
    }
    
    if ( Math.abs(calSum(right)-target) >= Math.abs(calSum(left)-target)){
        return left;
    }else{
        return right;
    }
    
};