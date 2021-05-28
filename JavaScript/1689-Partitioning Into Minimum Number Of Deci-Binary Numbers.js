/**
 * @param {string} n
 * @return {number}
 */
var minPartitions = function(n) {
    return parseInt(Math.max(...n.split("")));
};