/**
 * @param {number[]} nums
 * @return {number}
 */
var smallestIndex = function(nums) {
    function somaDigitos (n) {
        let resposta = 0;
        while (n > 0) {
            resposta += n % 10;
            n = Math.floor (n / 10);
        }
        return resposta;
    }
    for ([i, v] of nums.entries ()) {
        if (i === somaDigitos (v)) {
            return i;
        }
    }
    return -1; // Por omissão
};
