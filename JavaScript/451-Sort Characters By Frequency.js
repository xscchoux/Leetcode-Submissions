/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
    let hmap = new Map();
    for (let c of s){
        hmap.set(c, (hmap.get(c)||0) + 1);
    }
    let arr = [...hmap.keys()];
    arr.sort(function(a, b){
        return hmap.get(b) - hmap.get(a);
    })
    let res = "";
    for (let x of arr){
        for (let i=0; i<hmap.get(x); i++){
            res += x;
        }
    }
    return res;
};