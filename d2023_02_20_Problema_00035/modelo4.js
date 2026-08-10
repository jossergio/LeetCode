/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let i = 0, j = nums.length - 1;
    while (i <= j) {
        let meio = Math.floor ((i + j) / 2);
        if (nums [meio] === target) {
            return meio;
        }
        // else
        if (target > nums [meio]) {
            i = meio + 1;
        } else {
            j = meio - 1;
        }
    }
    return i; // Por omissão é esse valor
};
