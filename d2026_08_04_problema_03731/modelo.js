/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findMissingElements = function(nums) {
    nums.sort ((a, b) => a - b);
    let a = nums [0]; // Acompanhar
    let resposta = [];
    for (let i = 0; i < nums.length; i += 1) { 
        while (a !== nums [i]) {
            resposta.push (a++);
        }
        a += 1; // Segue para o próximo
    }
    return resposta;
};
