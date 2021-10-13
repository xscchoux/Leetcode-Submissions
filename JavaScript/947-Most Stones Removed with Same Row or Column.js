/**
 * @param {number[][]} stones
 * @return {number}
 */
var removeStones = function(stones) {
    let parent = new Map();
    
    let find = (x) =>{
        if ( x !== parent.get(x)){
            parent.set(x, find(parent.get(x)));
        }
        return parent.get(x);
    }
    
    let union = (x, y) =>{
        if (!parent.has(x)) parent.set(x, x);
        if (!parent.has(y)) parent.set(y, y);
        
        const px = find(x), py = find(y);
        if (px !== py) parent.set(px, py);
    }
    
    for (let [x, y] of stones){
        union(x, ~y);
    }
    
    let rootSet = new Set();
    for (let p of parent.keys()){
        rootSet.add(find(p));
    }
    
    return stones.length - rootSet.size;
};