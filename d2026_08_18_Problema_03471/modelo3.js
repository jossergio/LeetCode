/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestInteger = function(nums, k) {
    let cont = new Array (51).fill (0); // 1-50
    for (let i = 0; i < nums.length - k + 1; i += 1) {
        for (let c of new Set (nums.slice (i, i + k))) {
            cont [c] += 1;
        }
    }
    let resp = -1;
    for (let [i, c] of cont.entries ()) {
        if (c === 1) {
            resp = i;
        }
    }
    return resp;
};
