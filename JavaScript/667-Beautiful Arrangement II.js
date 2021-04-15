/**
 * @param {number} n
 * @param {number} k
 * @return {number[]}
 */
var constructArray = function(n, k) {
    let left = 1, right = n;
    let tmp = k;
    let isOdd = true;
    let res = [];
    
    while (tmp > 0){
        if (isOdd){
            res.push(left);
            left++;
        }else{
            res.push(right);
            right--;
        }
        tmp--;
        isOdd = !isOdd;
    }
    
    if (k%2){
        for (let i=left; i<=right; i++){
            res.push(i);
        }
    }else{
        for (let j=right; j>=left; j--){
            res.push(j);
        }
    }
    return res;
};