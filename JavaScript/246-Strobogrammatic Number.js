/**
 * @param {string} num
 * @return {boolean}
 */
var isStrobogrammatic = function(num) {
    const hmap = new Map([["0","0"], ["8","8"], ["1","1"], ["6","9"], ["9","6"]]);
    let left = 0, right = num.length-1;
    while (left <= right){
        if (!hmap.has(num[left]) || hmap.get(num[left]) !== num[right]){
            return false;
        }
        else{
            left++; right--;
        }
    }
    return true;
};