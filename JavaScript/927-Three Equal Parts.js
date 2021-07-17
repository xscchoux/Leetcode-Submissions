/**
 * @param {number[]} arr
 * @return {number[]}
 */
var threeEqualParts = function(arr) {
    const ones = arr.filter(x=> x===1).length;
    if (ones === 0){
        return [0,2];
    }
    
    if (ones%3){
        return [-1,-1];
    }
    const target = ones/3;
    const n = arr.length;
    let cnt = 0;
    let p1=0, p2=0, p3=0;
    
    for (let i=0; i<n; i++){
        if (arr[i] === 1){
            if (cnt === 0){
                p1 = i;
            }else if(cnt === target){
                p2 = i;
            }else if(cnt === 2*target){
                p3 = i;
            }
            cnt++;
        }
    }
    
    const oldP2 = p2, oldP3 = p3;
    while (p1 < oldP2 && p2 < oldP3 && p3 < n){
        if (arr[p1] !== arr[p2] || arr[p2] !== arr[p3]){
            return [-1,-1];
        }else{
            p1++;p2++;p3++;
        }
    }
    
    return (p3===n)?[p1-1, p2]:[-1,-1];
};