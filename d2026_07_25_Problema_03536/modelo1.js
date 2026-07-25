/**
 * @param {number} n
 * @return {number}
 */
var maxProduct = function(n) {
    let digs = [];
    while (n > 0) {
        digs.push (n % 10);
        n = Math.floor (n / 10);
    }
    digs.sort ((a, b) => b - a);
    return digs [0] * digs [1];
}; 
