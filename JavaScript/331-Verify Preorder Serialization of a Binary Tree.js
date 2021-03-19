/**
 * @param {string} preorder
 * @return {boolean}
 */
var isValidSerialization = function(preorder) {
    let slot = 1;
    for (let node of preorder.split(",")){
        slot -= 1;
        if (slot < 0) return false;
        if (node !== '#'){
            slot += 2;
        }
    }
    return slot === 0;
};