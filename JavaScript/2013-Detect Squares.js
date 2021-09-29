
var DetectSquares = function() {
    this.points = new Map();
};

/** 
 * @param {number[]} point
 * @return {void}
 */
DetectSquares.prototype.add = function(point) {
    let [x, y] = point;
    if (!this.points.has(y)){
        this.points.set(y, new Map());
        this.points.get(y).set(x, 1);
    }else{
        this.points.get(y).set(x, (this.points.get(y).get(x) || 0) + 1);
    }
};

/** 
 * @param {number[]} point
 * @return {number}
 */
DetectSquares.prototype.count = function(point) {
    let [currX, currY] = point;
    let otherX = this.points.get(currY)||new Map();
    let res = 0;
    
    let getNum = (yy, xx) =>{
        if (this.points.get(yy)){
            if (this.points.get(yy).get(xx)){
                return this.points.get(yy).get(xx);
            }else{
                return 0;
            }
        }else{
            return 0;
        }
    }

    for (const x of otherX.keys()){
        if (currX !== x){
            let diff = Math.abs(currX-x);
            res += getNum(currY, x)*getNum(currY+diff,x)*getNum(currY+diff,currX);
            res += getNum(currY, x)*getNum(currY-diff,x)*getNum(currY-diff,currX);
        }
    }
    return res;
};

/** 
 * Your DetectSquares object will be instantiated and called as such:
 * var obj = new DetectSquares()
 * obj.add(point)
 * var param_2 = obj.count(point)
 */