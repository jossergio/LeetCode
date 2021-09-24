func tribonacci(n int) int {
	var tribs = [] int {0, 1, 1}
	switch n {
		case 0: return 0
		case 1: return 1
		case 2: return 1
	// Sem default
	} // switch n
	var tmp int
	for a := 3; a <= n; a++ {
		tmp = tribs [a - 1] + tribs [a - 2] + tribs [a - 3]
		tribs = append (tribs, tmp)
	} // for a
	return tribs [n]
}

