/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let resposta = strs [0]; // Pressupõe
    for (let s of strs) {
        if (resposta.length == 0) { break; } // Nâo precisa mais seguir
        resposta = resposta.substring (0, Math.min (resposta.length, s.length));
        for (let i = 0; i < resposta.length; i += 1) {
            if (!(s [i] === resposta [i])) {
                resposta = resposta.substring (0, i);
                break; // Nâo precisa mais seguir daqui
            }
        }
    }
    return resposta; // Só chega aqui se todos forem iguais
};
