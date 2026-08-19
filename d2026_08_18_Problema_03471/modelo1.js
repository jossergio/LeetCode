/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestInteger = function(nums, k) {
    let cont = new Map ();
    for (let i = 0; i < nums.length - k + 1; i += 1) {
        let conj = new Set ();
        for (let j = 0; j < k; j += 1) {
            conj.add (nums [i + j]);
        }
        for (let c of conj) {
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
