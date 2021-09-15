/**
 * @param {number[]} arr
 * @return {number}
 */
var maxTurbulenceSize = function(arr) {
    let smaller=1, larger = 1;
    let res = 1;
    
    for (let i=1; i<arr.length; i++){
        let currLarger = 1, currSmaller = 1;
        if (arr[i] > arr[i-1]){
            currLarger = smaller + 1;
        }else if (arr[i] < arr[i-1]){
            currSmaller = larger + 1;
        }
        
        res = Math.max(res, currLarger, currSmaller);
        [larger, smaller] = [currLarger, currSmaller];
    }
    
    return res;
};