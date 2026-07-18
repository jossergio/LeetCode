/**
 * @param {number[]} nums
 * @return {number}
 */
var findGCD = function(nums) {
    function mdc (a, b) {
        if (a < b) {
            [a, b] = [b, a];
        }
        let calc = (a, b) => a % b === 0 ? b : mdc (b, a % b);
        return calc (a, b);
    }
    nums.sort ((a, b) => a - b);
    return mdc (nums [0], nums [nums.length - 1]);
};
