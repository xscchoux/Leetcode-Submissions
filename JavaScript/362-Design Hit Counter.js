/**
 * Initialize your data structure here.
 */
var HitCounter = function() {
    this.count = [];
};

/**
 * Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). 
 * @param {number} timestamp
 * @return {void}
 */
HitCounter.prototype.hit = function(timestamp) {
    this.count.push(timestamp);
};

/**
 * Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). 
 * @param {number} timestamp
 * @return {number}
 */
HitCounter.prototype.getHits = function(timestamp) {
    if (timestamp <= 300){
        return this.count.length;
    }else{
        let time = timestamp - 300;
        let left = 0, right = this.count.length-1;
        while (left + 1 < right){
            let mid = left + Math.floor((right-left)/2);
            if (this.count[mid] > time){
                right = mid;
            }else{
                left = mid;
            }
        }
        
        if (this.count[left] > time){
            return this.count.length - left;
        } else if (this.count[right] > time){
            return this.count.length - right;
        } else{
            return 0;
        }
    }
};

/** 
 * Your HitCounter object will be instantiated and called as such:
 * var obj = new HitCounter()
 * obj.hit(timestamp)
 * var param_2 = obj.getHits(timestamp)
 */