/**
 * @param {string[]} votes
 * @return {string}
 */
var rankTeams = function(votes) {
    let hmap = new Map();
    const N = votes[0].length;
    
    for (let word of votes[0]){
        hmap.set(word, new Array(N).fill(0) );
    }
    
    for (let vote of votes){
        for (let i=0; i<N; i++){
            hmap.get(vote[i])[i] += 1;
        }
    }
    
    let res = [...votes[0]];

    res.sort((a,b)=>{
        for (i=0; i<N; i++){
            if (hmap.get(a)[i] !== hmap.get(b)[i]){
                return hmap.get(b)[i] - hmap.get(a)[i];
            }
        }
        return a.charCodeAt(0) - b.charCodeAt(0);
    })
    
    return res.join("")
};