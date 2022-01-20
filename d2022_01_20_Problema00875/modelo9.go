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
	
    var tamanho int = len (piles)

	if tamanho == 1 {
		return divisao (piles[0], h) // Adiantando
	}

	maior, menor := pegarMaiorMenor (piles)

	if maior == menor { // Também adiantando
		return maior // Tanto faz
	}

	if tamanho == h {
		return maior // Não há como ser outro
	}

	menor = 1 // Ajusta

	for menor < maior { // Para ter um referencial limite de saída; pode retornar antes

		var meio int = (menor + maior) / 2
        var divisoes int = 0
        
		for _, pilha := range piles {
			divisoes += divisao (pilha, meio)
		} // for pilha

		if divisoes <= h {
			maior = meio
        } else {
            menor = meio + 1
        }

	} // while minimo < Maior

	return maior // Se chegar aqui, é esse. Porém, não sei se chega
}

