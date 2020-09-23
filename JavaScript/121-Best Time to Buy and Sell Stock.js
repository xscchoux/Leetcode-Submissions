/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let res = 0, min = Number.POSITIVE_INFINITY
    for (let price of prices){
        min = Math.min(min, price);
        res = Math.max(price-min, res);
    }
    return res;
};