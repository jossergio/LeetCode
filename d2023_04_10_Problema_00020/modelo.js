/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let pilha = [];
    let mapa = new Map ([['}', '{'], [']', '['], [')', '(']]);
    for (let c of s) {
        if (c === '{' || c === '[' || c === '(') {
            pilha.push (c);
        } else { // Só podem ser fechamentos)
            if (pilha.length > 0 && pilha [pilha.length - 1] === mapa.get (c)) {
                pilha.pop ();
            } else {
                return false; // Alguma sequência não foi correta
            }
        }
    }
    return pilha.length === 0; // Todos foram consumidos por terem sido dispostos corretamente
};
