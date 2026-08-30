/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var shortestBeautifulSubstring = function(s, k) {
    let possiveis = [];
    let menor = Infinity;
    let i = 0;
    let j = 0;
    let cont = 0;
    while (j < s.length) {
        while (j < s.length && cont < k) {
            if (s.charAt (j) === "1") {
                cont += 1;
            }
            j += 1;
        }
        while (i < j && cont === k) {
            let tmp = s.substring (i, j);
            possiveis.push (tmp);
            menor = Math.min (menor, tmp.length);
            if (s.charAt (i) === "1") {
                cont -= 1;
            }
            i += 1;
        }
    }
    let resp = "";
    for (p of possiveis) {
        if (p.length === menor) {
            if (resp === "" || p < resp) {
                resp = p;
            }
        }
    }
    return resp;
};
