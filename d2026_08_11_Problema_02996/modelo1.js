/**
 * @param {number[]} nums
 * @return {number}
 */
var missingInteger = function(nums) {
    let soma = nums [0];
    let ant = nums [0];
    let i = 1;
    while (i < nums.length && ant + 1 === nums [i]) {
        soma += nums [i];
        ant = nums [i];
        i += 1; 
    }
    nums.sort ((a, b) => a - b);
    i = 0; // Reutiliza
    while (i < nums.length && soma > nums [i]) {
        i += 1;
    }
    while (i < nums.length && soma === nums [i]) {
        while (i < nums.length && soma === nums [i]) { // Dispensa duplicados
            i += 1;
        }
        soma += 1;
    }
    return soma;
};
