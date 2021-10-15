var quadrados [] int

func qtdQuadrados (valor int, item int, nivel int, acumulado int) int {
// item começa pelo fim
	nivel++ // Vem por valor
	var retorno int = 0
	for item >= 0 {
		valor -= quadrados [item]
		if valor == 0 {
			return nivel
		} else { // if acumulado == n
			if valor > 0 {
				tmp := qtdQuadrados (valor, item, nivel, acumulado)
				if retorno == 0 && tmp != 0 {
					retorno = tmp
				} else { // if retorno == 0
					if tmp < retorno && tmp != 0 {
						retorno = tmp
					} // if tmp < retorno && tmp != 0
				} // else if retorno == 0
			} // if valor > 0
		valor += quadrados [item]
		item-- // Vem do fim do vetor de quadrados
		} // else if valor == 0
	} // for inicio > 0
	return retorno
} // qtdQuadrados

func numSquares(n int) int {
	var potencia, base int = 1, 1 // Primeiro quadrado; primeira base
	quadrados = nil
	for potencia <= n {
		quadrados = append (quadrados, potencia)
		base++
		potencia = base * base
	} // for valor <= n
	return qtdQuadrados (n, len (quadrados) - 1, 0, 0)
}

