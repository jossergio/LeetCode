/**
 * @param {number} n
 * @return {number}
 */
var maxProduct = function(n) {
    let primeiro = 0;
    let segundo = 0;
    while (n > 0) {
        let tmp = n % 10;
        if (tmp >= segundo) {
            if (tmp > primeiro) {
                segundo = primeiro;
                primeiro = tmp;
            } else { // Só é maior que os segundo
                segundo = tmp;
            }
        }
        n = Math.floor (n / 10);
    }
    return primeiro * segundo;
}; 
