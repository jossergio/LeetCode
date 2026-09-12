/**
 * @param {number[]} digits
 * @return {number}
 */
var totalNumbers = function(digits) {
    let digitos = new Map ();
    for (let d of digits) {
        digitos.set (d, digitos.has (d) ? digitos.get (d) + 1 : 1);
    }
    let valores = Array.from (digitos.keys ());
    let resposta = 0;
    for (let v1 of valores.filter (a => a % 2 === 0)) {
        let q1 = digitos.get (v1);
        digitos.set (v1, q1 - 1);
        for (let [v2, q2] of digitos.entries ()) {
            if (q2 > 0) {
                digitos.set (v2, q2 - 1);
                for (let [v3, q3] of digitos.entries ()) {
                    if (v3 !== 0 && q3 !== 0) {
                        resposta += 1;
                    }
                }
                digitos.set (v2, q2);
            }
        }
        digitos.set (v1, q1);
    }
    return resposta;
};
