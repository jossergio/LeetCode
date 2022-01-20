func pegarMaiorMenor (valores [] int) (maior int, menor int) {

	maior = valores [0]
	menor = valores [0]

	for _, v := range valores {

		if v > maior {
			maior = v
		}

		if v < menor {
			menor = v
		}

    }

	return // maior, menor
} // pegarMaiorMenor

func divisao (dividendo int, divisor int) (quociente int) {
	// Retorna a divisão superior (ceil)

	quociente = dividendo / divisor

	if dividendo % divisor != 0 {
		quociente += 1
	}

	return // quociente
} // divisao

func minEatingSpeed(piles []int, h int) int {
	if len (piles) == 1 {
		return divisao (piles [0], h) // Adiantando
	}

	maior, menor := pegarMaiorMenor(piles)

	if maior == menor { // Também adiantando
		return maior // Tanto faz
	}

	var minimo = 1

	for minimo <= maior { // Para ter um referencial limite de saída; pode retornar antes

		var peloMenor int = 0

		for _, pilha := range piles {
			peloMenor += divisao (pilha, minimo)
		} // for pilha

		if peloMenor <= h { // Fim da condição
			return minimo
		}

		minimo++

	} // while minimo < maior

	return divisao (maior, h) // Se chegar aqui, é esse. Porém, não sei se chega
}

