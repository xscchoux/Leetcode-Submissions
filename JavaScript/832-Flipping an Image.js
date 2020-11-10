/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
    return A.map(row=>{
        let newRow = row.reverse();
        return newRow.map(e=>1-e)
    })
    
};