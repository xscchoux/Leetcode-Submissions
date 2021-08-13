/**
 * @param {string[][]} tickets
 * @return {string[]}
 */
// Time complexity: O(|E|^d), where ∣E∣ is the number of total flights, and d is the maximum number of flights from an airport.

// For each position, we could have d choices. i.e. at each airport one could have have at most d possible destinations.
// Since the length of the sequence is |E|, the total number of combination would be |E|^d 
 .
var findItinerary = function(tickets) {
    let graph = new Map();
    let visited = new Map();
    let N = tickets.length;
    
    tickets.sort(function(a,b){return a[1] > b[1]? 1 : -1;})
    
    for (let [start, end] of tickets){
        if (!graph.has(start)){
            graph.set(start, []);
            visited.set(start, []);
        }
        graph.get(start).push(end);
        visited.get(start).push(false);
    }

    res = [];
    
    let dfs = (start, path) =>{
        if (path.length === N+1){
            res = path;
            return true;
        }
        if (!graph.get(start)) return;
        for (let i=0; i < graph.get(start).length; i++){
            let nxt = graph.get(start)[i];
            if (!visited.get(start)[i]){
                visited.get(start)[i] = true;
                path.push(nxt);
                if (dfs(nxt, path)){
                    return true;
                }
                path.pop();
                visited.get(start)[i] = false;
            }
        }
        
        return false;
    }
    dfs("JFK", ["JFK"]);
    return res;
};