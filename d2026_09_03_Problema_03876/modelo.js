/**
 * @param {number[]} nums1
 * @return {boolean}
 */
var uniformArray = function(nums1) {
    nums1.sort ((a, b) => a - b);
    let teste = nums1 [0] % 2 === 1; // Condição onde consigo deixar todos ímpares
    if (!teste) {
        let contImpares = 0;
        for (v of nums1) {
            if (v % 2 === 1) {
                return false; // Tem ímpar pelo meio e isso prejudica
            }
        }
    }
    return true;
};
