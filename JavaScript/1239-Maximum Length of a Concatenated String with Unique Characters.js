/**
 * @param {string[]} arr
 * @return {number}
 */
var maxLength = function(arr) {
    res = 0
    
    let backtracking = (start, string) =>{
        res = Math.max(res, string.length);
        
        for (let i=start; i<arr.length; i++){
            let newString = string + arr[i];
            if (newString.length === new Set([...newString]).size ){
                backtracking(i+1, newString);
            }
        }
    }
    
    backtracking(0, '');
    return res;
    
};