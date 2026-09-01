/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    let [ant, prox] = [0, 1];
    while (n > 0) {
        const tmp = prox;
        prox = ant + prox;
        ant = tmp;
        n -= 1;
    }
    return prox;
};
