/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @param {number} d
 * @return {number}
 */
var findTheDistanceValue = function(arr1, arr2, d) {
    arr2 = arr2.map (a => -a); // Inverte o sinal
    console.log (arr2);
    arr2.sort ((a, b) => a - b);
    console.log (arr2);
    let resposta = 0;
    for (let v of arr1) {
        if (arr2.findIndex (a => Math.abs (v + a) <= d) === -1) { // O sinal em arr2 é invertido
            resposta += 1;
        }
    }
    return resposta;
};
