/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	            -1 if num is lower than the guess number
 *			             1 if num is higher than the guess number
 *                       otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
var guessNumber = function(n) {
    let left = 1, right = n+1;
    while (true){
        const guessed = left + ((right-left)>>1);
        const res = guess(guessed);
        if (res === -1) right = guessed;
        else if (res === 1) left = guessed;
        else return guessed;
    }
};
