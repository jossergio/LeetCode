/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves = function(nums) {
   nums.sort ((a, b) => b - a);
   const maior = nums [0];
   return nums.map (v => maior - v).reduce ((t, a) => t + a, 0);
};
