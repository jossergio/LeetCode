/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let resposta = "";
    let menor = strs [0].length; // Só para referências
    for (let s of strs) {
        menor = Math.min (s.length, menor);
    }
    for (let i = 0; i < menor ; i += 1) {
        let tmp = strs [0][i]; // Para referência
        for (let s of strs) {
            if (s [i] != tmp) {
                return resposta; // Com o que tiver, pois a partir daqui não irá mais coincidir
            }
        }
        resposta += tmp;
    }
    return resposta; // Só chega aqui se todos forem iguais
};
