type StreamChecker struct {
	Prefixos  [] string
	Acumulado [] byte
}


func Constructor(words []string) StreamChecker {
	var p StreamChecker
	p.Prefixos = make ([] string, len (words))
	copy(p.Prefixos, words)
	return p

}

func (this *StreamChecker) verificarPalavra (palavra string) bool {
	var contadorAcumulado = len (this.Acumulado) - 1
	var contadorPalavra = len (palavra) - 1
	for contadorAcumulado >= 0 && contadorPalavra >= 0 {
		if palavra [contadorPalavra] != this.Acumulado [contadorAcumulado] {
			return false
		} // if
		contadorAcumulado--
		contadorPalavra--
	} // for ...
	if contadorPalavra >= 0 { // O stream é menor que a palavra em questão
		return false
	} // if contadorPalavra > 0
	return true // É o padrão; o algoritmo verifica se não é
} // StreamChecker.verificarPalavra

func (this *StreamChecker) Query(letter byte) bool {
	this.Acumulado = append (this.Acumulado, letter)
	for _, palavra := range this.Prefixos {
		if palavra [len (palavra)-1] == letter {
			if this.verificarPalavra (palavra) {
				return true // Pois, se for falso, não faz nada
			} // if this.verificarPalavra
		} // if palavra len palavra == letter
	} // for palavra := range this.Prefixos
	return false // É o padrão. o algoritmo testa as possibilidades
}


/**
 * Your StreamChecker object will be instantiated and called as such:
 * obj := Constructor(words);
 * param_1 := obj.Query(letter);
 */

