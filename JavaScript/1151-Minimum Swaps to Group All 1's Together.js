/**
 * @param {number[]} data
 * @return {number}
 */
var minSwaps = function(data) {
    let ones = data.reduce((acc, x)=>acc+x);
    if (ones === 0) return 0;
    
    let currOne = maxOne = data.slice(0, ones).reduce((acc,x)=>acc+x);
    
    for (let i=ones; i<data.length; i++){
        currOne += data[i] - data[i-ones];
        maxOne = Math.max(maxOne, currOne);
    }
    return ones - maxOne;
};