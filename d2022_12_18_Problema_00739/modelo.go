func dailyTemperatures(temperatures []int) []int {
	tamanho := len (temperatures) // Será usado várias vezes
	var resultado [] int
	var acumulado int
	for i := 0; i < tamanho - 1; i++ {
		acumulado = 1 // Inicia
		i2 := i + 1 // Preciso do valor ao final
		for i2 < tamanho {
			if temperatures [i] >= temperatures [i2] {
				acumulado++
			} else { // if temperatures >= temperatures [i2]
				break
			} // else if temperatures [i] >= temperatures [i2]
			i2++
		} // for i2
		if ! (i2 < tamanho) {
			acumulado = 0 // Acumulou e não encontrou
		} // if ! i2 < tamanho
		resultado = append (resultado, acumulado)
	} // for i, v
	resultado = append (resultado, 0) // Sempre termina assim; o último não tem comparativos
	return resultado
}

