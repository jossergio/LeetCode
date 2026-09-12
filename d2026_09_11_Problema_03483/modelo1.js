/**
 * @param {number[]} digits
 * @return {number}
 */
var totalNumbers = function(digits) {
    let digitos = new Map ();
    for (let d of digits) {
        digitos.set (d, digitos.has (d) ? digitos.get (d) + 1 : 1);
    }
    let resposta = 0;
    for (let b = 0; b < 9; b += 2) {
        if (digitos.has (b)) {
            digitos.set (b, digitos.get (b) - 1);
            for ([v, q] of digitos.entries ()) {
                if (q > 0) {
                    digitos.set (v, q - 1);
                    for ([v2, q2] of digitos.entries ()) {
                        if (v2 !== 0 && q2 > 0) {
                            resposta += 1;
                        }
                    }
                    digitos.set (v, q);
                }
            }
            digitos.set (b, digitos.get (b) + 1);
        }
    }
    return resposta;
};
