/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestInteger = function(nums, k) {
    let cont = new Array (51).fill (0); // 1-50
    for (let n of nums) {
        cont [n] += 1;
    }
    let resp = -1;
    switch (k) {
        case 1:
            for (let [i, c] of cont.entries ()) {
                if (c === 1) {
                    resp = i;
                }
            }
            break;
        case nums.length:
            resp = Math.max (...nums);
            break;
        default:
            if (cont [nums [0]] === 1) {
                resp = nums [0];
            }
            if (cont [nums [nums.length - 1]] === 1) {
                resp = Math.max (resp, nums [nums.length - 1]);
            }
            break; 
    }
    return resp;
};
