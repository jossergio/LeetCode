/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    let resposta = 1;
    while (resposta * resposta <= x) {
        resposta += 1;
    }
    return resposta - 1;
};
