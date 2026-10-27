/**
 * @param {number} m
 * @param {number} n
 * @return {string[]}
 */
var createGrid = function(m, n) {
    let resposta = new Array ();
    resposta.push (new Array (n).fill (".").join (""));
    let tmp = new Array (n).fill ("#");
    tmp [n - 1] = ".";
    let linha = tmp.join ("");
    for (let i = 1; i < m; i += 1){
        resposta.push (linha);
    }
    return resposta;
};
