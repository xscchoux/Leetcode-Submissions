/**
 * @param {number[]} arr
 * @return {boolean}
 */
var canReorderDoubled = function(arr) {
    let hmap = new Map();
    for (let num of arr){
        hmap.set(num, (hmap.get(num) || 0) + 1 );
    }
    arr.sort(function(a,b){
        if(a < 0 && b < 0) return b-a;
        return a-b;
    })
    
    for (let num of arr){
        if (hmap.get(num) > 0){
            if (hmap.get(num*2) > 0){
                hmap.set(num, hmap.get(num)-1);
                hmap.set(num*2, hmap.get(num*2)-1);
            }else{
                return false;
            }
        }
    }
    
    return true;
};