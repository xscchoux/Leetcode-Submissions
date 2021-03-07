/**
 * @param {number[]} arr
 * @return {number}
 */
var numFactoredBinaryTrees = function(arr) {
    arr.sort(function(a,b){
        return a-b;
    });
    let hmap = new Map();
    let res = 0;
    for (let i=0; i<arr.length; i++){
        hmap.set(arr[i], 1);
        for (let j=0; j<i; j++){
            if (arr[i]%arr[j] === 0 && hmap.has(arr[i]/arr[j])){
                hmap.set(arr[i], hmap.get(arr[i]) + hmap.get(arr[j])*hmap.get(arr[i]/arr[j]) );
            }
        }
        res += hmap.get(arr[i])%(10**9 + 7);
    }
    return res%(10**9+7);
};