var quadrados [] int

func qtdQuadrados (valor int, item int, nivel int, acumulado int, limite int) int {
// item começa pelo fim
	nivel++ // Vem por valor
	if nivel > limite {
		return 0 // Já retorna
	} // if nivel > limite
	var retorno int = 0
	for item >= 0 {
		valor -= quadrados [item]
		if valor == 0 {
			return nivel
		} else { // if acumulado == n
			if valor > 0 {
				tmp := qtdQuadrados (valor, item, nivel, acumulado, limite)
				if (tmp != 0) && (retorno == 0 || tmp < retorno) {
					retorno = tmp
					limite = tmp
				} // else if (tmp != 0) && (retorno == 0 || tmp < retorno)
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
	return qtdQuadrados (n, len (quadrados) - 1, 0, 0, 10000)
}

