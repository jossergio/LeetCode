/**
 * @param {number[]} nums
 * @return {number}
 */
var findGCD = function(nums) {
    let min = nums [0]; // Referência
    let max = nums [0]; // Idem
    for (let a of nums) {
        min = Math.min (min, a);
        max = Math.max (max, a);
    }
    let resp = 1; // Genérico
    for (let a = 0; a <= min; a += 1) {
        if (min % a === 0 && max % a === 0) {
            resp = a;
        }
    }
    return resp;
};
