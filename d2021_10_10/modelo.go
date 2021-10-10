func rangeBitwiseAnd(left int, right int) int {
	acumulador := left & right
	for a := left; a <= right; a++ {
        	acumulador &= a
		if acumulador == 0 {
			return 0
		}
	} // for a
	return acumulador
}

