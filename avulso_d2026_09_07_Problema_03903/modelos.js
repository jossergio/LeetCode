/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var firstStableIndex = function(nums, k) {
    let maiores = new Array (nums.length);
    let menores = new Array (nums.length);
    maiores [0] = nums [0];
    menores [nums.length - 1] = nums [nums.length - 1];
    for (let i = 1; i < nums.length; i += 1) {
        maiores [i] = Math.max (maiores [i - 1], nums [i]);
        menores [nums.length - i - 1] = Math.min (menores [nums.length - i], nums [nums.length -i - 1]);
    }
    for (let i = 0; i < nums.length; i += 1) {
        if (maiores [i] - menores [i] <= k) {
            return i;
        }
    }
;   return -1;
};
