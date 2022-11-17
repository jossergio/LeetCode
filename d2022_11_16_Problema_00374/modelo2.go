/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
    var i int = 1 // Menor possível
    // n será usado para sempre manter o limite superior
    for i < n {
        chute := (i + n) / 2
        switch guess (chute) {
            case 0: return chute
            case -1: n = chute - 1
            case 1: i = chute + 1
        }
    }
    return n // Só chega aqui se forem iguais
}

