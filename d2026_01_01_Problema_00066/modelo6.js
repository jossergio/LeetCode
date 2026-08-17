/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    for (let i = digits.length - 1; i >= 0; i -= 1) {
        if (digits [i] === 9) {
            digits [i] = 0; // Pressupõe o vai um
        } else {
            digits [i] += 1;
            return digits;
        }
    }
    return digits.toSpliced (0, 0, 1); // Se chegou aqui, é porque teve um vai um
};
