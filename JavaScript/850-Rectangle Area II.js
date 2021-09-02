/**
 * @param {number[][]} rectangles
 * @return {number}
 */

// BigInt is a built-in object whose constructor returns a bigint primitive — also called a BigInt value, 
// or sometimes just a BigInt — to represent whole numbers larger than 2^53 - 1

var rectangleArea = function(rectangles) {
    const kMod = BigInt(1000000007);
    
    let getArea = (xrange)=>{
        let area = 0n, prevTop = 0;
        
        for (let [bottom, top] of interval){
            let currBottom = Math.max(prevTop, bottom);
            if (top > currBottom){
                area += BigInt(xrange)*BigInt(top-currBottom);
                area %= kMod
                prevTop = top;
            }
        }
        return area%kMod;
    }
    
    let event = new Array();
    for (let [x1, y1, x2, y2] of rectangles){
        event.push([x1, 0, y1, y2]);
        event.push([x2, 1, y1, y2]);
    }
    event.sort(function(a, b){
        return a[0]-b[0];
    })
    
    let interval = new Array();
    let res = 0n, xPrev = 0;
    for (let [x, flag, y1, y2] of event){
        if (x!==xPrev){
            res += getArea(x-xPrev);
            res %= kMod;            
        }

        if (flag === 1){
            for (let i=0; i<interval.length; i++){
                if (interval[i][0] === y1 && interval[i][1] === y2){
                    interval.splice(i, 1);
                    break;
                }
            }
        }else{
            interval.push([y1, y2]);
            interval.sort(function(a,b){
                return a[0] - b[0];
            })
        }
        xPrev = x;
    }
    return parseInt(res);
};