/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var firstStableIndex = function(nums, k) {
    for (let i = 0; i < nums.length; i += 1) {
        if ((Math.max (...nums.slice (0, i + 1)) - Math.min (...nums.slice (i, nums.length))) <= k) {
            return i;
        }
    }
    return -1;
};
