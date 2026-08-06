/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
var smallestNumber = function(n, t) {
    let a = n;
    let prod = 1; // Elemento neutro da multiplicação
    while (a > 0) {
        prod *= a % 10;
        a = Math.floor (a / 10);
    }
    return prod % t === 0 ? n : smallestNumber (n + 1, t);
};
