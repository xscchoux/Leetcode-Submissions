/**
 * @param {number} num
 * @return {number}
 */
var maximumSwap = function(num) {
    let numArr = [... (num+"")].map(Number);
    let maxIdx = numArr.length-1;
    let swapSmall = null, swapLarge = null;
    
    for (let i = numArr.length-2; i>=0; i--){
        if(numArr[i] > numArr[maxIdx]){
            maxIdx = i;
        } else if(numArr[i] < numArr[maxIdx]){
            [swapSmall, swapLarge] = [i, maxIdx];
        }
    }
    if (swapSmall !== null){
        [numArr[swapSmall], numArr[swapLarge]] = [numArr[swapLarge], numArr[swapSmall]];
    }

    return Number(numArr.map(String).join(""));
};