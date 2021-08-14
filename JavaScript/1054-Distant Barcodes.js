/**
 * @param {number[]} barcodes
 * @return {number[]}
 */
var rearrangeBarcodes = function(barcodes) {
    const N = barcodes.length;
    let res = [];
    let hmap = new Map();
    
    for (let code of barcodes){
        hmap.set(code, (hmap.get(code)||0) + 1);
    }
    
    let arr = Array.from(hmap.keys()).sort(function(a, b){
        return hmap.get(b) - hmap.get(a);
    })
    
    let index = 0;
    
    for (let key of arr){
        for (let i=0; i<hmap.get(key); i++){
            res[index] = key;
            index += 2;
            if (index>=N){
                index = 1;
            }
        }
    }
    
    return res;
};