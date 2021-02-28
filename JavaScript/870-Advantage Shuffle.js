/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var advantageCount = function(A, B) {
    indexedB = B.map(function(val, index){
        return [val, index];
    })
    indexedB.sort(function(a, b){
        return a[0] - b[0];
    })
    
    let j = 0;
    let res = new Array(A.length);
    A.sort(function(a,b){return a-b;});
    
    for (let a of A){
        if (a > indexedB[j][0]){
            res[indexedB[j][1]] = a;
            j++;
        }else{
            res[indexedB.pop()[1]] = a;
        }
    }
    
    return res;
};