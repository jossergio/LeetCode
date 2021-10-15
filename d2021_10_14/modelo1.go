var quadrados [] int
var valor int

func qtdQuadrados (item int, nivel int, acumulado int) int {
// item começa pelo fim
	nivel++ // Vem por valor
	var retorno int = 0
	for item >= 0 {
		acumulado += quadrados [item]
		if acumulado == valor {
			return nivel
		} else { // if acumulado == n
			if acumulado < valor {
				tmp := qtdQuadrados (item, nivel, acumulado)
				if retorno == 0 && tmp != 0 {
					retorno = tmp
				} else { // if retorno == 0
					if tmp < retorno && tmp != 0 {
						retorno = tmp
					} // if tmp < retorno && tmp != 0
				} // else if retorno == 0
			} // if acumulado < n
			acumulado -= quadrados [item]
			item-- // Vem do fim do vetor de quadrados
		} // else if acumulado == n
	} // for inicio > 0
	return retorno
} // qtdQuadrados

func numSquares(n int) int {
	var potencia, base int = 1, 1 // Primeiro quadrado; primeira base
	quadrados = nil
	valor = n
	for potencia <= n {
		quadrados = append (quadrados, potencia)
		base++
		potencia = base * base
	} // for valor <= n
	return qtdQuadrados (len (quadrados) - 1, 0, 0)
}

