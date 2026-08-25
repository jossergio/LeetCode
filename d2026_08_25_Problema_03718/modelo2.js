/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var missingMultiple = function(nums, k) {
    let m = Math.max (...nums) + k; // Inclui a possibilidsde de estar além
    let s = new Set ();
    for (let n = k; n <= m; n += k) {
        s.add (n);
    }
    for (let n of nums) {
        if (s.has (n)) {
            s.delete (n);
        }
    }
    return Math.min (...s);
};
