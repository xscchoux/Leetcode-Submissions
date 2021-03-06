/**
 * @param {number[][]} routes
 * @param {number} source
 * @param {number} target
 * @return {number}
 */
var numBusesToDestination = function(routes, source, target) {
    let stopToRoute = new Map();
    for (let [routeIdx, route] of routes.entries()){
        for (let stop of route){
            stopToRoute.set(stop, [routeIdx].concat(stopToRoute.get(stop) || []) );
        }
    }
    
    let visitedBus = new Set();
    let queue = [[source, 0]];
    
    while (queue.length){
        let [currStop, count] = queue.shift();
        if (currStop === target){
            return count;
        }
        for(let routeIdx of stopToRoute.get(currStop)){
            if (!visitedBus.has(routeIdx)){
                visitedBus.add(routeIdx);
                for (let nxtStop of routes[routeIdx]){
                    queue.push([nxtStop, count+1]);
                }
            }
        }
    }
    return -1;
};