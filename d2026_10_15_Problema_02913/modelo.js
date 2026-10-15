/**
 * @param {number[]} nums
 * @return {number}
 */
var sumCounts = function(nums) {
    let resposta = 0;
    for (let i = 0; i < nums.length; i += 1) {
        let unicos = new Set ();
        for (let j = i; j < nums.length; j += 1) {
            unicos.add (nums [j]);
            resposta += unicos.size * unicos.size;
        }
    }
    return resposta;
};
