/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestInteger = function(nums, k) {
    let cont = new Map ();
    for (let i = 0; i < nums.length - k + 1; i += 1) {
        for (let c of new Set (nums.slice (i, i + k))) {
            cont.set (c,
                cont.has (c) ? cont.get (c) + 1 : 1
            );
        }
    }
    let resp = -1;
    for (let [i, c] of cont.entries ()) {
        if (c === 1) {
            resp = Math.max (resp, i);
        }
    }
    return resp;
};
