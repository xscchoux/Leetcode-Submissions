/**
 * @param {number} jug1Capacity
 * @param {number} jug2Capacity
 * @param {number} targetCapacity
 * @return {boolean}
 */
var canMeasureWater = function(jug1Capacity, jug2Capacity, targetCapacity) {
    let [x, y, z] = [jug1Capacity, jug2Capacity, targetCapacity];
    if (x+y<z) return false;
    let gcd = (a, b)=>{
        if (a===0) return b;
        [a, b] = [b%a, a];
        return gcd(a, b);
    }

    return z%gcd(x,y) === 0;
};