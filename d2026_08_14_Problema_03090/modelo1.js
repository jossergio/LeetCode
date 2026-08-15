/**
 * @param {string} s
 * @return {number}
 */
var maximumLengthSubstring = function(s) {
    let mapa = new Map ();
    let resposta = 0;
    let i = 0;
    for (let j = 0; j < s.length; j += 1) {
        let c = s [j]; // Facilita visualização
        if (mapa.has (c)) {
            let tmp = mapa.get (c);
            if (tmp.length === 2) {
                if (tmp [0] >= i) {
                    i = tmp [0] + 1;
                }
                tmp [0] = tmp [1];
                tmp [1] = j;
            } else { // Só pode ser 1
                tmp [1] = j; // Adiciona
            }
            mapa.set (c, tmp);
        } else {
            mapa.set (c, [j]);
        }
        resposta = Math.max (resposta, j - i + 1);
        console.log (mapa, i, j, resposta);
    }
    return resposta;
};
