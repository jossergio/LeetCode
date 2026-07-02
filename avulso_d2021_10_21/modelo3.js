/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let s = x.toString ();
    let i = 0;
    let j = s.length - 1
    while (i < j) {
        if (s [i] != s [j]) {
            return false;
        }
        i += 1;
        j -= 1;
    }
    return true; // Passou nos testes
};
