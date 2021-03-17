/**
 * @param {number[]} prices
 * @param {number} fee
 * @return {number}
 */
var maxProfit = function(prices, fee) {
    let without = 0, holding = -prices[0]-fee;
    
    for (let i=1; i<prices.length; i++){
        [without, holding] = [Math.max(without, holding + prices[i]), Math.max(holding, without-prices[i]-fee)];
    }
    return without;
};