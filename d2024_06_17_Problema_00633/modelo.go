func judgeSquareSum(c int) bool {
	var b int
	raiz := int (math.Sqrt (float64 (c)))

	for a:= raiz; a >= 0; a-- {
		b = int (math.Sqrt (float64 (c - (a * a))))
		for ((a * a) + (b * b)) <= c {
			if ((a * a) + (b * b)) == c {
				return true
			} // if ...
			b++
		} // for {interno}
	} // for a
	return false
}

