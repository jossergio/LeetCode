func maxNumberOfBalloons(text string) int {
	letras := make (map [rune] int)
	letras ['b'] = 0
	letras ['a'] = 0
	letras ['l'] = 0
	letras ['o'] = 0
	letras ['n'] = 0
	maximo := 2000 // Valor inferido para máximo (sei que é menor que isso)
	for _, letra := range text {
		switch rune (letra) {
			case 'b', 'a', 'l', 'o', 'n': letras [rune (letra)] += 1
		} // switch a
	} // for letra range text
	for indice, valor := range letras {
		if indice == 'l' || indice == 'o' {
			valor = valor / 2
		} // if indice...
		if valor < maximo {
			maximo = valor
		} // if valor < maximo
	} // for indice, valor range letras
	return maximo
}

