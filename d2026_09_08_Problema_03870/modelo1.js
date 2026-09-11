/**
 * @param {number} n
 * @return {number}
 */
var countCommas = function(n) {
    let resp = 0;
    for (let i = 1000; i <= n; i += 1) {
        resp += 1;
    }
    return resp;
};
