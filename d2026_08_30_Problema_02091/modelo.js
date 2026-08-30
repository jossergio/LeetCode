/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDeletions = function(nums) {
    let [iMenor, iMaior, menor, maior] =
        [0, 0, Infinity, -Infinity];
    for ([i, v] of nums.entries ()) {
        if (v > maior) {
            iMaior = i;
            maior = v;
        }
        if (v < menor) {
            iMenor = i;
            menor = v;
        }
    }
    return iMenor < iMaior ?
        Math.min (iMaior + 1, nums.length - iMenor, (iMenor + 1) + (nums.length - iMaior)):
        Math.min (iMenor + 1, nums.length - iMaior, (iMaior + 1) + (nums.length - iMenor));
};
