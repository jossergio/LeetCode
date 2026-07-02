/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let t = nums.length
    for (let i = 0; i < t; i += 1) {
        for (let j = i + 1; j < t; j += 1) {
            if (nums [i] + nums [j] == target) {
                return [i, j];
            }
        }
    }
    return [0, 0]; // Só para ter algo aqui
};
