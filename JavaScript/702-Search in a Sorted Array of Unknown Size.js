/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * function ArrayReader() {
 *
 *     @param {number} index
 *     @return {number}
 *     this.get = function(index) {
 *         ...
 *     };
 * };
 */

/**
 * @param {ArrayReader} reader
 * @param {number} target
 * @return {number}
 */
var search = function (reader, target) {
    let left = 0, right = 1;
    
    while (reader.get(right) < target){
        left = right;
        right*=2;
    }
    
    while (left + 1 < right){
        const mid = left + ((right-left)>>1);
        const num = reader.get(mid);
        if (num < target){
            left = mid;
        } else if (num > target){
            right = mid;
        } else{
            return mid;
        }
    }
    
    if (reader.get(left) == target){
        return left;
    } else if (reader.get(right) == target){
        return right;
    } else{
        return -1;
    }
};