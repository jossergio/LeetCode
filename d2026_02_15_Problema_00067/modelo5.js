/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    let n1 = a.split ("").map (c => c === "0" ? 0 : 1);
    let n2 = b.split ("").map (c => c === "0" ? 0 : 1);
    switch (Math.sign (n1.length - n2.length)) { // Não precisa testar o zero
        case -1:
            n1 = ajustar (n1, n2.length - n1.length);
            break;
        case 1:
            n2 = ajustar (n2, n1.length - n2.length);
            break;
    }
    let vaiUm = 0;
    // n1 será utilizado para resposta
    for (let i = n1.length - 1; i >= 0; i -= 1) {
        switch (n1 [i] + n2 [i] + vaiUm) {
            case 0: break; // Nâo precisa fazer nada
            case 1: n1 [i] = 1; vaiUm = 0; break;
            case 2: n1 [i] = 0; vaiUm = 1; break;
            case 3: n1 [i] = 1; vaiUm = 1; break;
        }
    }
    if (vaiUm === 1) {
        n1.splice (0, 0, 1); // Adicionao o vai um
    }
    return n1.join ("");
};

function ajustar (n, t) {
    let tmp = Array.from (new Array (t));
    tmp = tmp.map (x => x === undefined ? 0 : x);
    return tmp.concat (n);
}
