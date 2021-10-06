/**
 * @param {number[]} stones
 * @return {boolean}
 */
var stoneGameIX = function(stones) {
    let hmap = new Map();
    
    for (let stone of stones){
        hmap.set(stone%3, (hmap.get(stone%3)||0) + 1);
    }
    
    if ( (hmap.get(0)||0)%2 === 0){
        return (hmap.get(1)||0) && (hmap.get(2)||0);
    }else{
        return Math.abs( (hmap.get(1)||0) - (hmap.get(2)||0) ) >= 3;
    }
};