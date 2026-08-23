/**
 * @param {number} n
 * @return {boolean}
 */
var checkDivisibility = function(n) {
    let soma = 0; // Elemento neutro da adição
    let prod = 1; // Elemento neutro da multiplicação
    let k = n; // Manter n para o final
    while (k > 0) {
        let tmp = k % 10;
        soma += tmp;
        prod *= tmp;
        k = Math.floor (k / 10);
    }
    return (n % (soma + prod) === 0); // Não há divisão por zero aqui
};
