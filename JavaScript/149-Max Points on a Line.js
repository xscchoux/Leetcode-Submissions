/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
    if (points.length <= 2) return points.length;
    
    let res = 2;
    for (let i=0; i<points.length-2; i++){
        let duplicate = 1, currX = points[i][0], currY = points[i][1];
        let count = new Map();
        for (let nxt of points.slice(i+1)){
            let nxtX = nxt[0], nxtY = nxt[1];
            if (nxtX === currX){
                if (nxtY === currY){
                    duplicate += 1;
                }else{
                    count.set('inf', (count.get('inf') || 0) + 1 );
                }
            }else{
                let slope = (nxtY-currY)/(nxtX-currX);
                count.set(slope, (count.get(slope)||0) + 1);
            }
        }
        res = Math.max(res, duplicate + Math.max(...count.values()));
    }
    return res;
};