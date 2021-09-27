/**
 * @param {number[][]} buildings
 * @return {number[][]}
 */
var averageHeightOfBuildings = function(buildings) {
    let points = new Array();
    
    for (let [start, end, height] of buildings){
        points.push([start, 1, height]);
        points.push([end, -1, height]);
    }
    
    points.sort(function(a,b){return a[0]-b[0];})
    let res = [];
    
    let currH = 0, count = 0, prevX = 0;
    for (let [currX, kind, height] of points){
        if (count!==0 && prevX!==currX){
            let avgH = Math.floor(currH/count);
            if (res.length && res[res.length-1][1] === prevX && avgH === res[res.length-1][2]){
                res[res.length-1][1] = currX;
            }else{
                res.push([prevX, currX, avgH]);
            }
        }
        count += kind;
        currH += kind*height;
        prevX = currX;
    }
    
    return res;
};