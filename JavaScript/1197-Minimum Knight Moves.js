/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var minKnightMoves = function(x, y) {
    let visited = new Set();
    let queue = [[0,0,0]]
    // console.log(queue.shift())
    visited.add(`0-0`);
    
    x = Math.abs(x);
    y = Math.abs(y);
    
    while (queue.length){
        let size = queue.length;
        for (let i=0; i<size; i++){
            let [currX, currY, step] = queue.shift();
            // console.log(currX, currY, step);
            if (currX === x && currY === y){
                return step;
            }
            for (let [dx, dy] of [[1,2], [2,1], [-1,2], [-2,1], [-1,-2], [-2,-1], [1,-2], [2,-1]]){
                let newX = currX + dx, newY = currY + dy;
                if (newX >=-2 && newY >= -2 && newX <= x+2 && newY <= y+2 && !visited.has(`${newX}-${newY}`)){
                    visited.add(`${newX}-${newY}`);
                    queue.push([newX, newY, step+1]);
                }
            }
        }
    }
};