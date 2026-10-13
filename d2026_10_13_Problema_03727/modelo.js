/**
 * @param {number[]} nums
 * @return {number}
 */
var maxAlternatingSum = function(nums) {
    nums = nums.map (Math.abs);
    nums.sort ((a, b) => b - a);
    let meio = Math.floor (nums.length / 2) - (1 - (nums.length % 2)); // Que intuição
    let resp = 0;
    for (let [i, v] of nums.entries ()) {
        if (i <= meio) {
            resp += v * v;
        } else {
            resp -= v * v;
        }
    }
    return resp;
};
