/**
 * @param {string} s
 * @return {number}
 */
var reverseDegree = function(s) {
    let resposta = 0;
    let z = 'z'.charCodeAt ();
    for (let [i, c] of Array.from (s).entries ()) {
        resposta += (i + 1) * (z - c.charCodeAt () + 1);
    }
    return resposta;
};
