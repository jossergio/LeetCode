/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let tmp = s.trim (); // Retira brancos desnecessários
    let resposta = tmp.length; // Por omissão, caso haja somente uma palavra, será esse valor
    for (let i = 0; i < s.length; i += 1) {
        if (tmp [i] === ' ') {
            resposta = tmp.length - (i + 1); // i tem a posição do branco
        }
    }
    return resposta;
};
