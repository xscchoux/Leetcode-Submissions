/**
 * @param {number[]} milestones
 * @return {number}
 */
var numberOfWeeks = function(milestones) {
    const mx = Math.max(...milestones), tot = milestones.reduce(function(acc, x){return acc+x;});
    
// https://stackoverflow.com/questions/596467/how-do-i-convert-a-float-number-to-a-whole-number-in-javascript
// Note that the bitwise operators operate on 32 bit numbers. They won't work for numbers too large to fit in 32 bits.
    if (mx <= (tot/2)|0 ){
        return tot;
    }else{
        return 2*(tot-mx) + 1;
    }
};