/**
 * @constructor
 * @param {Integer[]} v1
 * @param {Integer[]} v1
 */
var ZigzagIterator = function ZigzagIterator(v1, v2) {
    this.arr = new Array();
    for (let v of [v1, v2]){
        if (v.length > 0) this.arr.push(v);
    }
    this.queue = new Array();    
    for (let vIndex=0; vIndex < this.arr.length; vIndex++){
        this.queue.push([vIndex, 0]);
    }
};


/**
 * @this ZigzagIterator
 * @returns {boolean}
 */
ZigzagIterator.prototype.hasNext = function hasNext() {
    return this.queue.length > 0
};

/**
 * @this ZigzagIterator
 * @returns {integer}
 */
ZigzagIterator.prototype.next = function next() {
    [vIndex, itemIndex] = this.queue.shift();
    if (itemIndex < this.arr[vIndex].length-1){
        this.queue.push([vIndex, itemIndex+1]);
    }
    return this.arr[vIndex][itemIndex];
};

/**
 * Your ZigzagIterator will be called like this:
 * var i = new ZigzagIterator(v1, v2), a = [];
 * while (i.hasNext()) a.push(i.next());
*/