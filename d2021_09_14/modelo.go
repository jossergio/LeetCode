unc reverseOnlyLetters(s string) string {
	var a int = 0;
	var b int = len (s) - 1
	const letras string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
	var retorno [] string = strings.Split (s, "")
	for a < b {
		for a < b && strings.IndexByte (letras, s [a]) == -1 {
			a++
		}
		for b > a && strings.IndexByte (letras, s [b]) == -1 {
			b--
		}
		if (a < b) {
			retorno [a], retorno [b] = retorno [b], retorno [a]
		}
		a++
		b--
	} // for a < b
	return strings.Join (retorno, "")
}

