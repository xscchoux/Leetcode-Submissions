/**
 * @param {number[]} arr
 * @return {number}
 */
var minSetSize = function(arr) {
    const N = arr.length;
    let arrCount = new Map();
    for (let num of arr){
        arrCount.set(num, (arrCount.get(num)||0) + 1 );
    }
    sortedCount = [...arrCount.values()].sort((a, b) => b-a);
    
    let count = 0;
    let ans = 0;
    
    while (count < N/2){
        count += sortedCount[ans];
        ans += 1;
    }
    return ans
};