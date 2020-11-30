/**
 * @param {number[]} arr
 * @param {number} start
 * @return {boolean}
 */
var canReach = function(arr, start) {
    let queue = [start];
    
    while (queue.length){
        let curr = queue.shift();
        if (arr[curr] === 0){
            return true;
        }
        if (arr[curr] < 0){
            continue;
        }
        if (curr + arr[curr] < arr.length){
            queue.push(curr+arr[curr]);
        }
        if (curr - arr[curr] >= 0){
            queue.push(curr-arr[curr]);
        }
        arr[curr] = -arr[curr];
    }
    return false;
};