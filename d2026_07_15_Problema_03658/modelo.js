/**
 * @param {number} n
 * @return {number}
 */
var gcdOfOddEvenSums = function(n) {
    let pares = 0;
    let impares = 0;
    n = n * 2; // Duas listas intercaladas
    for (let i = 1; i <= n; i += 1) {
        if (i % 2 == 0) {
            pares += i;
        } else {
            impares += i;
        }
    }
    function mdc (a, b) {
        while (a > 0) {
            let tmp = b % a;
            b = a;
            a = tmp;
        }
        return b;
    }
    return mdc (impares, pares); // par sempre é o maior; não precisa checar
};
