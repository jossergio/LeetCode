/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
var smallestNumber = function(n, t) {
    function mult (a) {
        let resp = 1; // Elemento neutro ds multiplicação
        while (a > 0) {
            resp *= a % 10;
            a = Math.floor (a / 10);
        }
        return resp;
    }
    while (true) {
        if (mult (n) % t === 0) {
            return n;
        }
        n += 1;
    }
};
