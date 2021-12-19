/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var kIncreasing = function(arr, k) {
    let LIStotlen = 0;
    let bisectRight = (curr, num) =>{
        let left = 0, right = curr.length-1;
        while (left + 1 < right){
            let mid = left + ((right-left)>>1);
            if (curr[mid] > num){
                right = mid;
            }else{
                left = mid;
            }
        }
        if (curr[left] > num){
            return left;
        }else{
            return right;
        }
    }
    
    for (let start=0; start<k; start++){
        let curr = new Array();
        for (let i=start; i<arr.length; i+=k){
            if (curr.length === 0 || arr[i] >= curr[curr.length-1]){
                curr.push(arr[i]);
            }else{
                curr[bisectRight(curr, arr[i])] = arr[i];
            }
        }
        LIStotlen += curr.length;
    }
    return arr.length - LIStotlen;
};