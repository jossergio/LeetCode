/**
 * @param {number} num
 * @param {number} sum
 * @return {string}
 */
var maxSumOfSquares = function(num, sum) {
    let resp = new Array ();
    while (num > 0) {
        let digito = Math.min (sum, 9);
        resp.push (digito);
        sum -= digito;
        num -= 1;
    }
    return sum === 0 ? resp.join ("") : "";
};
