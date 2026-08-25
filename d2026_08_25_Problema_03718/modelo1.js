/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var missingMultiple = function(nums, k) {
    nums.sort ((a, b) => a - b);
    let i = 0;
    let fator = 1;
    while (i < nums.length && nums [i] <= fator * k) {
        if (nums [i] === fator * k) {
            fator += 1;
        }
        i += 1;
    }
    return fator * k;
};
