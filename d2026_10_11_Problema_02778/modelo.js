/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfSquares = function(nums) {
    let resp = 0;
    let n = nums.length;
    for (let [i, v] of nums.entries ()) {
        if (n % (i + 1) == 0) {
            resp += v * v;
        }
    }
    return resp;
};
