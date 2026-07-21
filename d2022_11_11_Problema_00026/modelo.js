/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let k = 0;
    let t = nums.length;
    for (let i = 0; i < t; i += 1) {
        if (nums [k] !== nums [i]) { // O primeiro elemento acaba sendo comparado com ele mesmo
            k += 1;
            nums [k] = nums [i];
        }
    }
    return k + 1; // Tem que retornar o tamanho total e não o último índice; 0-begin
};
