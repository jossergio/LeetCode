/**
 * @param {number} n
 * @return {number}
 */
var sumAndMultiply = function(n) {
    let soma = 0;
    let digs = 0;
    let pot = 1; // Potência a ser utilizada para o deslocamento
    while (n > 0) {
        let tmp = n % 10;
        n = Math.trunc (n / 10);
        soma += tmp;
        if (tmp != 0) {
            digs += pot * tmp;
            pot *= 10;
        }
    }
    return soma * digs;
};
