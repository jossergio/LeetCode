/**
 * @param {number[]} nums
 * @return {number}
 */
var gcdSum = function(nums) {
    function mdc (a, b) {
        if (a > b) {
            let tmp = a;
            a = b;
            b = tmp;
        }
        while (a != 0) {
            let r = b % a;
            b = a;
            a = r;
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
        resp += mdc (pre [i], pre [j]);
        i += 1;
        j -= 1;
    }
    return resp;
};
