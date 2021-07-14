/**
 * @param {string} order
 * @param {string} str
 * @return {string}
 */
var customSortString = function(order, str) {
    let hmap = new Map();
    const N = order.length;
    for (let i=0; i<N; i++){
        hmap.set(order[i], N-i);
    }
    let res = Array.from(str).sort(function(a, b){
        if (hmap.has(a) && hmap.has(b)){
            return hmap.get(b) - hmap.get(a);
        } else if(hmap.has(a)){
            return -1;
        }else if(hmap.has(b)) {
            return 1;
        }else{
            return 0;
        }
    })
    return res.join("");
};