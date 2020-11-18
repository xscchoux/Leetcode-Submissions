/**
 * @param {number} n
 * @return {number}
 */
var nextGreaterElement = function(n) {
    
    let arr = n.toString().split("");
    
    if (arr.length === 1) return -1;
    
    for (let i= arr.length-2; i>=0; i--){
        if (arr[i] < arr[i+1]){
            let index = arr.length-1;
            while (arr[i] >= arr[index]){
                index--;
            }
            [arr[i], arr[index]] = [arr[index], arr[i]];
            
            let left = i+1, right = arr.length-1;
            while(left<right){
                [arr[left], arr[right]] = [arr[right], arr[left]];
                left++; right--;
            }
            break;
        }
        if (i===0){
            return -1;
        }
    }
    
    let res = parseInt(arr.join(""));
    if (res > 2147483647){
        return -1;
    }else{
        return res;
    }
};