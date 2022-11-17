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
    var tentativa int // Temporário, no laço
    var chute int // Idem
    // n será usado para sempre manter o limite superior
    for i < n {
        chute = (i + n) / 2
        tentativa = guess (chute)
        if tentativa == 0 {
            return chute
        }
        // else
        if tentativa == 1 {
            i = chute + 1
        } else { // tentativa == -1
            n = chute - 1
        }
    }
    return n // Só chega aqui se forem iguais
}

