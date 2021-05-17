/**
 * @param {number[]} arr
 * @return {number}
 */
var longestMountain = function(arr) {
    let end  = 0, start = 0, N = arr.length;
    let res = 0;
    while (start < N){
        if (end + 1 < N && arr[end] < arr[end+1]){
            while (end + 1 < N && arr[end] < arr[end+1]){
                end++;
            }
            if (end + 1 < N && arr[end] > arr[end+1]){
                while (end + 1 < N && arr[end] > arr[end+1]){
                    end++;
                }
                res = Math.max(res, end-start+1);
            }
        }
        if (end == start){
            end = start + 1;
        }
        start = end;
    }
    return res;
};