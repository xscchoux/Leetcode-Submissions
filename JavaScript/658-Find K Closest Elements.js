/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findClosestElements = function(arr, k, x) {
    let left = 0, right = arr.length-k;
    while (left + 1 < right){
        let mid = left + Math.floor((right-left)/2);
        if (x - arr[mid] > arr[mid + k] - x){
            left = mid;
        }else{
            right = mid;
        }
    }
    if (left + k < arr.length && x - arr[left] > arr[left + k] - x){
        return arr.slice(right, right+k);
    }
    return arr.slice(left, left+k);
};