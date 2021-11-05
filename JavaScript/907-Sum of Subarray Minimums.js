/**
 * @param {number[]} arr
 * @return {number}
 */
var sumSubarrayMins = function(arr) {
    const kMod = Math.pow(10, 9) + 7;
    let stack = new Array(), res = 0;
    arr.unshift(Number.NEGATIVE_INFINITY);
    arr.push(Number.NEGATIVE_INFINITY);
    
    for (let [ind, num] of arr.entries()){
        while (stack.length && num < arr[stack[stack.length-1]]){
            let prevBigger = stack.pop();
            res += arr[prevBigger]*(ind-prevBigger)*(prevBigger-stack[stack.length-1]);
            res %= kMod;
        }
        stack.push(ind);
    }
    return res;
};