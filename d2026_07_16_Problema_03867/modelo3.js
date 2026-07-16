/**
 * @param {number[]} nums
 * @return {number}
 */
var gcdSum = function(nums) {
    function mdc (a, b) {
        if (a > b) {
            [a, b] = [b, a];
        }
        while (a != 0) {
            [b, a] = [a, b % a];
        }
        return b;
    }
    let maximo = nums [0];
    let pre = [];
    for (n of nums) {
        maximo = Math.max (maximo, n);
        pre.push (mdc (maximo, n));
    }
    pre.sort ((a, b) => a - b);
    let resp = 0;
    let i = 0;
    let j = pre.length - 1;
    while (i < j) {
        resp += mdc (pre [i++], pre [j--]);
    }
    return resp;
};
