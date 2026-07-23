/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let k = nums.length; 
    let i = 0;
    while (i < k) {
        if (nums [i] === val) {
            nums [i] = nums [--k];
        } else {
            i += 1;
        }
    }
    return k;
};
