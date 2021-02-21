/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    let i2=0, i3=0, i5=0;
    let arr = [1];
    
    while (arr.length < n){
        arr.push(Math.min(2*arr[i2],3*arr[i3],5*arr[i5]));
        if (arr[arr.length-1] === 2*arr[i2]) i2+=1;
        if (arr[arr.length-1] === 3*arr[i3]) i3+=1;
        if (arr[arr.length-1] === 5*arr[i5]) i5+=1;
    }
    
    return arr[arr.length-1];
};