/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let original = x;
    let reverso = 0;
    while (x > 0) {
        reverso *= 10; // Desloca para a direita
        reverso += x % 10; // Adiciona na direita (que ficou zero, na anterior)
        x = Math.floor (x / 10); // A divisão em JavaScript não é inteira
    }
    return original === reverso;
};
