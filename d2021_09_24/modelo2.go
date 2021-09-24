var gerado bool = false
var tribs = [] int {0, 1, 1}

func gerarTribs () {
	var tmp int
	for a := 3; a <= 37; a++ {
		tmp = tribs [a - 1] + tribs [a - 2] + tribs [a - 3]
		tribs = append (tribs, tmp)
	} // for a
} // gerarTribs

func tribonacci(n int) int {
	if !gerado {
		gerarTribs ()
	} // if !gerado
	return tribs [n]
}

