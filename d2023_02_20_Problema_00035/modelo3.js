/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    function buscaBinaria (nums, i, j) {
        if (i > j) {
            return i;
        }
        // else
        let meio = Math.floor ((i + j) / 2);
        return nums [meio] === target ? meio :
            target > nums [meio] ? buscaBinaria (nums, meio + 1, j) : buscaBinaria (nums, i, meio - 1);
    }
    return target < nums [0] ? 0 :
        target > nums [nums.length - 1] ? nums.length :
        buscaBinaria (nums, 0, nums.length  - 1);
};
