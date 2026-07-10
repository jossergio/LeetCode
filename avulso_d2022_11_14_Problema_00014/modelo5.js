/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let resposta = strs [0]; // Pressupõe
    for (let s of strs) {
        resposta = resposta.substring (0, Math.min (resposta.length, s.length));
        let prefixo = "";
        for (let i = 0; i < resposta.length && resposta [i] == s [i]; i += 1) {
            prefixo += resposta [i];
        }
        resposta = prefixo;
        if (resposta === "") {
            return resposta; // Para adiantar
        }
    }
    return resposta;
};
