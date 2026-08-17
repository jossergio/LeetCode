/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let resposta = [];
    let vaiUm = 1; // Já faz a adição básica no próprio vai um
    digits.reverse (); // O cálculo é feito da direita para a esquerda; mas os laços são da esquerda para a direita
    for (v of digits) {
        resposta.push ((v + vaiUm) % 10);
        vaiUm = Math.floor ((v + vaiUm) / 10);
    }
    if (vaiUm === 1) {
        resposta.push (1); // Caso tenho ocorrido
    }
    resposta.reverse (); // O cálculo é feito de forma reversa; então, temos que tornar
    return resposta;
};
