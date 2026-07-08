/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let valores = new Map ([
        ['I', 1],
        ['V', 5],
        ['X', 10],
        ['L', 50],
        ['C', 100],
        ['D', 500],
        ['M', 1000]
    ]);
    let tmp = valores.get (s [0]);
    let acumulado = 0;
    for (c of s.substring (1, s.length)) {
        if (tmp < valores.get (c)) {
            if (tmp === 0) {
                tmp = valores.get (c);
            } else {
                acumulado += valores.get (c) - tmp;
                tmp = 0;
            }
        } else {
            acumulado += tmp;
            tmp = valores.get (c);
        }
    }
    acumulado += tmp;
    return acumulado;
};
