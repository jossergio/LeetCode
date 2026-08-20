/**
 * @param {number[]} nums
 * @return {number[]}
 */
var resultArray = function(nums) {
    let a1 = [];
    let a2 = [];
    a1.push (nums [0]);
    a2.push (nums [1]);
    for (let v of nums.slice (2)) {
        if (a1 [a1.length - 1] > a2 [a2.length - 1]) {
            a1.push (v);
        } else {
            a2.push (v);
        }
    }
    return a1.concat (a2);
};
