/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
	var menor int = 1
	var maior int = n
	var chute int
	for menor <= maior {
// Sim, houve uma resposta errada se não for igual, pois, o limite pode ser 1 para o valor 1
// Sacanagens do LeetCode
		chute = (maior + menor) / 2
		// Farei três testes por vez
		if guess (menor) == 0 {
			chute = menor
			break
		} else { // if guess menor == 0
			if guess (maior) == 0 {
				chute = maior
				break
			} else { // if guess maior == 0
				resposta := guess (chute) // Poderemos ter três possibilidades
				switch {
					case resposta < 0: maior = chute
					case resposta > 0: menor = chute
					case resposta == 0: break
					// Não há outras possibilidades
				} // switch
			} // if guess maior == 0
		} // else if guess menor == 0
		menor++
		maior--
	} // for guess...
	return chute // Com certeza, o valor estará nessa variável
}

