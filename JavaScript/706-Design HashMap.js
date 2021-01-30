/**
 * Initialize your data structure here.
 */
var Bucket = function(){
    this.element = new Array();
};

Bucket.prototype.putValue = function(key, value){
    let found = false;
    for (let [index, element] of this.element.entries()){
        if (key === element[0]){
            this.element[index] = [key, value];
            found = true;
            break;
        }
    }
    if (!found){
        this.element.push([key, value]);
    }
};

Bucket.prototype.getValue = function(key){
    for (let [k, v] of this.element){
        if (key === k){
            return v;
        }
    }
    return -1;
};

Bucket.prototype.delete = function(key){
    for (let [index, element] of this.element.entries()){
        if (key === element[0]){
            this.element.splice(index, 1);
            break;
        }
    }
};


var MyHashMap = function() {
    this.bucketNum = 1033
    this.hashmap = new Array(this.bucketNum).fill(new Bucket());
};

/**
 * value will always be non-negative. 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
MyHashMap.prototype.put = function(key, value) {
    let hashNum = key%this.bucketNum;
    this.hashmap[hashNum].putValue(key, value);
};

/**
 * Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key 
 * @param {number} key
 * @return {number}
 */
MyHashMap.prototype.get = function(key) {
    let hashNum = key%this.bucketNum;
    return this.hashmap[hashNum].getValue(key);
};

/**
 * Removes the mapping of the specified value key if this map contains a mapping for the key 
 * @param {number} key
 * @return {void}
 */
MyHashMap.prototype.remove = function(key) {
    let hashNum = key%this.bucketNum;
    this.hashmap[hashNum].delete(key);
};

/** 
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */