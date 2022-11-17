/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
    var menor int = 1
    var maior int = n
    var chute int // = 0
    for menor <= maior {
        chute = (menor + maior) / 2
        switch guess (chute) {
            case -1: maior = chute - 1
            case 1: menor = chute + 1
            case 0: return chute
        }
    }
    return chute // Não deve chegar aqui
}

