/**
 * @param {number} n
 * @return {number}
 */
var countCommas = function(n) {
    let i = Math.floor (n / 1000);
    return i === 0 ? 0 :
        (i - 1) * 1000 + n % 1000 + 1; // Inclusive
};
