func judgeSquareSum(c int) bool {
	for a:= 0; (a * a) <= c; a++ {
		for b := a; (a * a) + (b * b) <= c; b++ {
			if ((a * a) + (b * b)) == c {
				return true
			} // if ...
		} // for b
	} // for a
	return false
}

