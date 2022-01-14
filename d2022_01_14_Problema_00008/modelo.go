import "math"

func myAtoi(s string) int {
	// Comprimento tem que ser maior que zero
	if ! (len (s) > 0) {
		return 0
	}

	var c int = 0

	// Elimina espaços iniciais
	for c < len (s) && s [c] == ' ' {
		c++
	}

	if ! (c < len (s)) {
		return 0
	}

	// O 1o caractere tem que ser número ou sinal
	if ! (s [c] == '+' || s [c] == '-' || (s [c] >= 0 && s [c] <= '9')) {
		return 0
	}

	var sinal int = 1

	if s [c] == '+' || s [c] == '-' {
		if s [c] == '-' {
			sinal = -1
		}
		c++ // Só
	}

	if ! (c < len (s)) {
		return 0
	}

	var sResposta string

	for (c < (len (s))) && (s [c] >= '0' && s [c] <= '9') {
		sResposta = string(s [c]) + sResposta
		c++
	} // for

	if ! (len(sResposta) > 0) {
		return 0
	}

	var resposta int

	for c = len (sResposta) - 1; c >= 0; c-- {
		unidade := int (sResposta [c] - '0')
		switch sinal {
		case -1:
			if (-resposta) < ((math.MinInt32 + unidade) / 10) {
				return math.MinInt32
			}
		case 1:
			if resposta > ((math.MaxInt32 - unidade) / 10) {
				return math.MaxInt32
			}
		} // switch

		resposta = resposta * 10 + unidade
	} // for c

	return sinal * resposta
}

