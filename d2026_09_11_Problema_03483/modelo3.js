/**
 * @param {number[]} digits
 * @return {number}
 */
var totalNumbers = function(digits) {
    let contagem = new Set ();
    for (let [i, v1] of digits.entries ()) {
        for (let [j, v2] of digits.entries ()) {
            for (let [k, v3] of digits.entries ()) {
                if (i !== j && i !== k && j !== k && v1 % 2 === 0 && v3 !== 0){
                    contagem.add (v1 + v2 * 10 + v3 * 100);
                }
            }
        }
    }
    return contagem.size;
};
