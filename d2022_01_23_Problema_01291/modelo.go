func sequentialDigits(low int, high int) []int {
	var base int = low
	var potencia10Base int = 0

	for base >= 10 {
		base /= 10
		potencia10Base += 1
	}

	var final int = high
	var potencia10Final = 0
	for final >= 10 {
		potencia10Final += 1
		final /= 10
	}

	var resposta [] int

	for inicial := 1; inicial < 9; inicial++ {
		tmp := inicial
		resp := 0
		for pot := 0; pot <= potencia10Final && tmp < 10; pot++ {
			resp += tmp
			if (resp >= low) && (resp <= high) {
				resposta = append(resposta, resp)
			}
			tmp += 1
			resp *= 10
		}
	}
    
    sort.Ints (resposta) // O LeetCode só aceitava ordenado
    
	return resposta
}

